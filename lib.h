#ifndef __LIB_H
#define __LIB_H
#include <sys/types.h>
#include <sys/socket.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>
#include <string.h>

int Socket();

void Bind(int sockfd, struct sockaddr *addr, socklen_t addrlen);

void Listen(int sockfd);

int Accept(int sockfd);

void Write(int sockfd, char *buf, int size);

int Read(int sockfd, char *buf, int size);

void Close(int sockfd);

void Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

void get_time(char *buf);
#endif