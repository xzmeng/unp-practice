#include "lib.h"

int main(){
    int listenfd, connfd;
    struct sockaddr_in addr;
    char buf[100];

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8888);
    addr.sin_addr.s_addr = INADDR_ANY;

    Bind(listenfd, (struct sockaddr *)&addr, sizeof(addr));

    Listen(listenfd);

    while(connfd = Accept(listenfd)){
        sleep(1);
        get_time(buf);
        Write(connfd, buf, strlen(buf));
        Close(connfd);
    }

    return 0;

}

