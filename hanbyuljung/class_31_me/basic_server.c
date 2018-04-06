#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include "server.h"

#define BUF_SIZE		128
#define MAX_CLNT		256
#define SET_TIMES		6


int cnt[MAX_CLNT];
//int clnt_cnt = 0;
int idx;
int clnt_socks[MAX_CLNT];
int thread_pid[MAX_CLNT];
//double runtime=0.0;
double load_ratio;
int flag;

pthread_mutex_t mtx;
tv start, end;

int main(int argc, char **argv)
{
	int serv_sock;
	int clnt_sock;

	si serv_addr;
	si clnt_addr;
	socklen_t clnt_addr_size;

	char msg[] = "Hello Network Programming";

	server_init(argc ,argv,&serv_sock,&clnt_sock,&serv_addr,&clnt_addr);
	// 이 억셉트를 for에 넣을건지 안넣을지를 결정한다.
	clnt_sock = accept_s(serv_sock,clnt_addr);
	
	// accept는 서버 소켓이 클라이언트의 실제 접속 허용을 해주는 곳이다.
	
	// 원격에 있는 클라이언트에게 롸이트를 한다.
	write(clnt_sock, msg, sizeof(msg));
	close(clnt_sock);
	close(serv_sock);

	return 0;
}

