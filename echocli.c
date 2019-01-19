#include "lib.h"

int main(){
    int sockfd;
    struct sockaddr_in servaddr;
    int n;

    sockfd = Socket();
    
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8888);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    Connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    char buf[100];
    while(1){
        fgets(buf, 100, stdin);
        n = strlen(buf);
        Write(sockfd, buf, n - 1);
        Read(sockfd, buf, n - 1);
        buf[n - 1] = '\0';
        printf("%s\n", buf);
    }

    return 0;
}