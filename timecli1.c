#include "lib.h"

int main(){
    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8888);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    Connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    char buf[100];
    bzero(buf, 100);
    int n;
    while( (n = read(sockfd, buf, 100) > 0)){
        fputs(buf, stdout);
    }

    return 0;
}