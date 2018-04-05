#ifndef __NETWORK_H__
#define __NETWORK_H__

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/epoll.h>
#include<pthread.h>
#include<setjmp.h>
#include<string.h>

typedef struct sockaddr_in si;
typedef struct sockaddr *	sp;
typedef struct timeval tv;

typedef struct __data{
	int clnt_sock;
	si n_clnt_addr;

}net_data;
void err_handler(char *);
double get_runtime(tv,tv);
void send_msg(char*, int , int*);
void *clnt_handler(void*);
void block_ip_init(void);
void block_ip_check(int, si);

#define BUF_SIZE	10000
#define MAX_CLNT    10000
#define NAME_SIZE   32
#endif
