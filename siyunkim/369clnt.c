#include "game.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <malloc.h>

#define BUF_SIZE		128

typedef struct sockaddr_in	si;
typedef struct sockaddr *	sp;
int sign;
char msg[BUF_SIZE];
int sock;

void my_sig(int signo)
{
	
	char buf[BUF_SIZE];
	int len;
	Data *data;
	data =(Data *)malloc(sizeof(Data));
	sign +=1;
	len = strlen(buf);
}


void err_handler(char *msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

void *send_msg(void *arg)
{
	sock = *((int *)arg);
	char msg[BUF_SIZE];
	Data *data;
	data = (Data *)malloc(sizeof(Data));


	for(;;)
	{
		signal(SIGINT,my_sig);
		read(0,data->ms,BUF_SIZE);	
		sprintf(data->signal,"%d",sign);	
		write(sock,data,sizeof(Data));
	sign=0;
	}

	return NULL;
}

void *recv_msg(void *arg)
{
	sock = *((int *)arg);
	char msg[BUF_SIZE];
	int str_len;

	Data *data;
	data = (Data *)malloc(sizeof(Data));

	for(;;)
	{
		str_len = read(sock,data->ms, BUF_SIZE - 1);

		data->ms[str_len] = 0;
		fputs(data->ms,stdout);
		fputs(data->signal,stdout);
	}

	return NULL;
}

int main(int argc, char **argv)
{
	sock;
	si serv_addr;
	pthread_t snd_thread, rcv_thread;
	void *thread_ret;

	sock = socket(PF_INET, SOCK_STREAM, 0);

	if(sock == -1)
		err_handler("socket() error");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));

	if(connect(sock, (sp)&serv_addr, sizeof(serv_addr)) == -1)
		err_handler("connect() error");

	pthread_create(&snd_thread, NULL, send_msg, (void *)&sock);
	pthread_create(&rcv_thread, NULL, recv_msg, (void *)&sock);
	pthread_join(snd_thread, &thread_ret);
	pthread_join(rcv_thread, &thread_ret);

	close(sock);

	return 0;
}
