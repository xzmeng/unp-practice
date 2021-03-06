#include "lib.h"

void handle(int connfd){
    char buf[100];
    get_time(buf);
    sleep(1);
    Write(connfd, buf, strlen(buf));
    exit(0);
}

int main(){
    int listenfd, connfd;
    struct sockaddr_in addr;
    char buf[100];
    int pid;

    listenfd = Socket();
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8888);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    Bind(listenfd, (struct sockaddr *)&addr, sizeof(addr));

    Listen(listenfd);

    while(connfd = Accept(listenfd)){
        if ((pid = fork()) == 0){
            Close(listenfd);
            handle(connfd);
        }
        Close(connfd);
    }

    return 0;

}

