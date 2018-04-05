#ifndef __LOAD_TEST_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include <sys/time.h>
#include<sys/epoll.h>
#include<malloc.h>

typedef struct timeval	tv;
typedef struct sockaddr_in si;
typedef struct sockaddr *sap;

void err_handler(char *msg);
void server_init(int argc , char **argv,int *serv_sock,int *clnt_sock, si *serv_addr,si *clnt_addr);
void send_msg(char *msg, int len);
double get_runtime(tv start, tv end);
int accept_s(int serv_sock,si clnt_addr );
int init_sock(void);
void init_sock_addr(si *, int, char **, int);
void post_sock(int, si *, int);


#endif
