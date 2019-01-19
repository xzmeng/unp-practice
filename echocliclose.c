#include "lib.h"
#include <stdio.h>
//打开多个客户端后，同时关闭
//如果服务器进程使用wait()来处理SIGCHLD则会出现未处理的defunct进程
//应使用waitpid() WNOHANG
int main(){

    for(int i = 0; i < 100; ++i){
        int sockfd;
        struct sockaddr_in servaddr;
        int n;

        sockfd = Socket();
        
        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(8888);
        servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        Connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    }
    
    getchar();

    return 0;
}