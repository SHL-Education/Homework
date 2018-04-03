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

#define BUF_SIZE		128
#define MAX_CLNT		256

typedef struct timeval	tv;
typedef struct sockaddr_in		si;
typedef struct sockaddr *		sp;

int clnt_cnt = 0;
int clnt_socks[MAX_CLNT];
pthread_mutex_t mtx;

// 카운트를 위한 구조체 
typedef struct __count
{
	int send_client[0];
}count;


void err_handler(char *msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

count *ct = 0;
// 시간을 구해주는 함수.
void get_runtime(tv start, tv end)
{
	end.tv_usec = end.tv_usec - start.tv_usec;
	end.tv_sec = end.tv_sec - start.tv_sec;
	end.tv_usec += end.tv_sec * 1000000;

	printf("runtime = %lf sec\n", end.tv_usec / 1000000.0);
}

void send_msg(char *msg, int len)
{
	int i;

	pthread_mutex_lock(&mtx);

	for(i = 0; i<clnt_cnt; i++)
		write(clnt_socks[i], msg, len);

	pthread_mutex_unlock(&mtx);
}
void *clnt_handler(void *arg)
{
	int clnt_sock = *((int *)arg);
	int str_len = 0, i;
	char msg[BUF_SIZE];
	char clnt_count[BUF_SIZE];
	
	while((str_len = read(clnt_sock , msg, sizeof(msg))) != 0){
		// 현재 말한 횟수 세는것은 한명만 된다.
		ct->send_client[clnt_cnt-1] += 1;
		sprintf(clnt_count,"[<말한 횟수(1.6):%d>]\n",ct->send_client[clnt_cnt-1]);
		write(clnt_socks[clnt_cnt-1], clnt_count, sizeof(clnt_count));
		send_msg(msg, str_len);
	}

	pthread_mutex_lock(&mtx);
	
	

	for(i = 0; i<clnt_cnt; i++){
		if(clnt_sock == clnt_socks[i])
		{
			while(i++ < clnt_cnt-1)
				clnt_socks[i] = clnt_socks[i+1];
			break;
		}
	}

	clnt_cnt --;
	pthread_mutex_unlock(&mtx);
	close(clnt_sock);

	return NULL;
}

int main(int argc, char **argv)
{
	int serv_sock, clnt_sock ;
	si serv_addr, clnt_addr;
	socklen_t addr_size;
	pthread_t t_id;

	unsigned int i, cnt = 0;
	tv start, end;

	ct = (count*)malloc(1024);

	gettimeofday(&start, NULL);

	for(i = 0; i < 777777777; i++)
		cnt++;

	gettimeofday(&end, NULL);

	// 여기서 시간을 구한다.
	get_runtime(start, end);


	if(argc != 2)
	{
		printf("Usage: %s <port>\n", argv[0]);
		exit(1);
	}

	pthread_mutex_init(&mtx, NULL);

	serv_sock = socket(PF_INET, SOCK_STREAM, 0);

	if(serv_sock == -1)
		err_handler("socket() error");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family =AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	if(bind(serv_sock, (sp)&serv_addr, sizeof(serv_addr)) ==-1)
		err_handler("bind() error");
	if(listen(serv_sock , 25)== -1)
		err_handler("listen() error!");

	for(;;)
	{
		addr_size = sizeof(clnt_addr);
		clnt_sock = accept(serv_sock,(sp)&clnt_addr, &addr_size);
		

		pthread_mutex_lock(&mtx);
		ct->send_client[clnt_cnt] = 0;
		clnt_socks[clnt_cnt++] = clnt_sock;
		pthread_mutex_unlock(&mtx);

		printf("clnt_cnt (사람수) : %d\n", clnt_cnt);

		pthread_create(&t_id, NULL, clnt_handler, (void *) &clnt_sock);
		pthread_detach(t_id);
		printf("Connected Client IP: %s\n", inet_ntoa(clnt_addr.sin_addr));
	}
	close(serv_sock);
	return 0;
}
	









