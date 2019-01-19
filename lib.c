#include "lib.h"
#include <errno.h>

int Socket(){
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1){
        printf("err socket");
        exit(1);
    }
    return fd;
}


void Bind(int sockfd, struct sockaddr *addr, socklen_t addrlen){
    int ret;
    ret = bind(sockfd, addr, addrlen);
    if (ret != 0){
        printf("err bind");
        printf("errno:%d\n", errno);
        exit(1);
    }
}

void Listen(int sockfd){
    int ret;
    ret = listen(sockfd, 5);
    if (ret != 0){
        printf("err listen");
        exit(1);
    }
}

int Accept(int sockfd){
    int ret;
    ret = accept(sockfd, NULL, NULL);
    if (ret == -1){
        printf("err accept");
        exit(1);
    }
    return ret;
}

void Write(int sockfd, char *buf, int size){
    if( size != write(sockfd, buf, size)){
        printf("err write");
        exit(1);
    }
}

int Read(int sockfd, char *buf, int size){
    int ret;
    ret = read(sockfd, buf, size);
    if (ret < 0){
        printf("err read");
        exit(1);
    }
    return ret;
}

void Close(int sockfd){
    int ret;
    ret = close(sockfd);
    if (ret == -1){
        printf("err close");
        exit(1);
    }
}

void Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen){
    int ret = connect(sockfd, addr, addrlen);
    if (ret != 0){
        printf("err connect");
        exit(1);
    }
}
