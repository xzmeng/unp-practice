#include "lib.h"
#include <ctype.h>
#include <signal.h>
#include <wait.h>

void upper(char *, int);
void sig_chld_handler();

void handler(int connfd){
    int n;
    char buf[100];
    while((n = Read(connfd, buf, 100)) != 0){
            buf[n] = '\0';
            printf("send:%s\n", buf);
            upper(buf, n);
            Write(connfd, buf, n);
    }
    printf("handler exit\n");
    exit(0);
}

void sigchld_handler(int signum){
    pid_t pid;
    int stat;
    pid = wait(&stat);
    printf("child %d terminated\n", pid);
    return ;
}

void upper(char *buf, int size){
    for (int i = 0; i < size; ++i){
        buf[i] = (char)toupper((int)buf[i]);
    }
}

int main(){
    int listenfd, connfd;
    struct sockaddr_in addr;
    int pid;
    char buf[100];
    int n;

    listenfd = Socket();
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8888);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    Bind(listenfd, (struct sockaddr *)&addr, sizeof(addr));

    Listen(listenfd);

    signal(SIGCHLD, sigchld_handler);

    while(connfd = Accept(listenfd)){
        if(( pid = fork() ) == 0){
            Close(listenfd);
            handler(connfd);
        }
        Close(connfd);
    }

    return 0;

}
