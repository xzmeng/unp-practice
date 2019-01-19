#include "lib.h"
#include <ctype.h>

void handle(int connfd){
    char buf[100];
    int n;

    while((n = Read(connfd, buf, 99) > 0)){
        Write(connfd, buf, n);
    }
    exit(0);
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

    while(connfd = Accept(listenfd)){
        while((n = Read(connfd, buf, 100)) != 0){
            buf[n] = '\0';
            printf("send:%s\n", buf);
            upper(buf, n);
            Write(connfd, buf, n);
        }
    }

    return 0;

}
