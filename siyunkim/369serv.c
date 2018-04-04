#include "game.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/socket.h>


#define	BUF_SIZE	128
#define MAX_CLNT	256

typedef struct sockaddr_in		si;
typedef struct sockaddr *		sp;

int clnt_cnt = 0;
int clnt_socks[MAX_CLNT];
int data[MAX_CLNT];
int dat=0;
int thread_pid[MAX_CLNT];
int idx;
int cnt[MAX_CLNT];
int lum;
int totalcnt=0;
pthread_mutex_t mtx; 

void err_handler(char *msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

void sig_handler(int signo)
{
	int i;

	printf("Time Over!\n");

	pthread_mutex_lock(&mtx);

	for(i = 0; i < clnt_cnt; i++)
		if(thread_pid[i] == getpid())
			{
			cnt[i] += 1;
			totalcnt +=1;
			}

	pthread_mutex_unlock(&mtx);

	alarm(3);
}



void proc_msg(Data *data, int k)
{
	int i;
	int cmp = atoi(data->ms);
	char smsg[64] = {0};
	char numc[1024];
	int ncnt=0;
	
	dat += 1;
	sprintf(numc,"%d",dat);

	pthread_mutex_lock(&mtx);
	totalcnt +=1;
	cnt[k] += 1;
	sprintf(smsg,"You Player[%d]\n",k);
	write(clnt_socks[k],smsg,strlen(smsg));
	
	for(i=0;numc[i];i++)
	{
		if(numc[i] =='3' || numc[i] == '6' || numc[i] == '9')
		{
				ncnt+=1;
		}
	}

	if(ncnt != 0)
	{
		printf("cnt3 =%d\n",ncnt);
		printf("dat= %d\n",dat);
		lum=atoi(data->signal);
		printf("lum = %d\n",lum);
		if(lum == ncnt)
		{
			sprintf(smsg,"Next turn %d\n",cmp);
		}
		else if(lum != ncnt)
		{
			sprintf(smsg,"youloose %d\n",cmp);
		}

	}
	else
	{

	if(dat > cmp){
		sprintf(smsg, "youloose %d\n", cmp);}
	else if(dat < cmp){
		sprintf(smsg, "you loose %d\n", cmp);}
	else
	{
		strcpy(smsg, "Next turn\n");
		printf("player[%d]cnt = %d\n",k, cnt[k]);
		printf("totalcnt = %d\n",totalcnt);
	}
	}
	strcat(smsg, "Input Number: \n");
	write(clnt_socks[k], smsg, strlen(smsg));



	pthread_mutex_unlock(&mtx); 
}

void *clnt_handler(void *arg)
{
	int clnt_sock = *((int *)arg);
	int str_len = 0, i;
	char msg[BUF_SIZE] = {0};
	char pattern[BUF_SIZE] = "Input Number: \n";
	signal(SIGALRM, sig_handler);

	pthread_mutex_lock(&mtx); 
	thread_pid[idx++] = getpid();

	Data *data;
	data =(Data *)malloc(sizeof(Data));

	i = idx - 1;
	printf("i = %d\n", i);
	write(clnt_socks[i], pattern, strlen(pattern));
	pthread_mutex_unlock(&mtx);
	alarm(3);

	while(read(clnt_sock,data,sizeof(Data)) !=0)
	{
		alarm(0);
		proc_msg(data,i);
		alarm(3);
	}

	pthread_mutex_lock(&mtx);

	for(i = 0; i < clnt_cnt; i++)
	{
		if(clnt_sock == clnt_socks[i])
		{
			while(i++ < clnt_cnt - 1)
				clnt_socks[i] = clnt_socks[i + 1];
			break;
		}
	}

	clnt_cnt--;
	pthread_mutex_unlock(&mtx);
	close(clnt_sock);

	return NULL;
}

int main(int argc, char **argv)
{
	int serv_sock, clnt_sock;
	si serv_addr, clnt_addr;
	socklen_t addr_size;
	pthread_t t_id;
	int idx = 0;

	if(argc != 2)
	{
		printf("Usage: %s <port>\n", argv[0]);
		exit(1);
	}

	srand(time(NULL));

	pthread_mutex_init(&mtx, NULL);


	serv_sock = socket(PF_INET, SOCK_STREAM, 0);

	if(serv_sock == -1)
		err_handler("socket() error");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	if(bind(serv_sock, (sp)&serv_addr, sizeof(serv_addr)) == -1)
		err_handler("bind() error");

	if(listen(serv_sock, 2) == -1)
		err_handler("listen() error");

	for(;;)
	{	
		
		addr_size = sizeof(clnt_addr);
		clnt_sock = accept(serv_sock, (sp)&clnt_addr, &addr_size);


		thread_pid[idx++] = getpid();
	
		pthread_mutex_lock(&mtx);
		

		clnt_socks[clnt_cnt++] = clnt_sock;
		pthread_mutex_unlock(&mtx);


		pthread_create(&t_id, NULL, clnt_handler, (void *)&clnt_sock);

		pthread_detach(t_id);


		printf("Connected Client IP: %s\n", inet_ntoa(clnt_addr.sin_addr));

	}

	close(serv_sock);

	return 0;
}
