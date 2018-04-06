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
// err 체크를 하는 함수 
void err_handler(char *msg);
//  서버에 기본적으로 쓰는 부분을 통으로 만듬, accept 전까지 만들었다.
void server_init(int argc , char **argv,int *serv_sock,int *clnt_sock, si *serv_addr,si *clnt_addr);
// 클라이언트가 메세지를 보낼 때를 위해서 만들었다.
void send_msg(char *msg, int len);
// 혹시 블록킹이나 타이밍을 재야 할 경우를 위해 만들었다.
double get_runtime(tv start, tv end);
// accept 부분을 위해 만들었다.
int accept_s(int serv_sock,si clnt_addr );
// socket 을 열은 fd를 받아 오는 함수
int init_sock(void);
// 소켓에서 마지막 옵션으로 serv=0, clnt=1 일때 IPv4 설정 port, 이름등을 받는 함수.
void init_sock_addr(si *, int, char **, int);
// bind 와 listen을 하는 함수
void post_sock(int, si *, int);


#endif
