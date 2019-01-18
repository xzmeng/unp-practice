#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    int cli_fd;
    cli_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8888);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(cli_fd, &serv_addr, sizeof(serv_addr)) != 0){
        printf("err connect");
        exit(1);
    }

    char buf[100];
    bzero(buf, 100);
    int n;
    while( (n = read(cli_fd, buf, 100) > 0)){
        fputs(buf, stdout);
    }

    return 0;
}