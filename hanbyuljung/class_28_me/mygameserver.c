// 박수 = Ctrl + c
// SIGALRM 은 2초 이다.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <setjmp.h>


#define BUF_SIZE	256
#define MAX_CLNT	512


typedef struct sockaddr_in		si;
typedef struct sockaddr *		sap;
int clnt_cnt = 0;
int clnt_socks[MAX_CLNT];
int data[MAX_CLNT];
int thread_pid[MAX_CLNT];
int idx;
int cnt[MAX_CLNT];
int preNum=0;

jmp_buf gogo;

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

	// 현재 쓰레드 PID를 가져온다.
	for(i = 0; i < clnt_cnt; i++)
		if(thread_pid[i] == getpid())			
			 pthread_kill(thread_pid[i], SIGINT);
			//cnt[i] += 1;	// 이게 현재 숫자라고 가정한다.
	pthread_mutex_unlock(&mtx);
	// 나중에 알람을 끄고 소켓이 꺼지게 해야한다.
	close(clnt_socks[idx-1]);
}

void sig_handler2(int signo)
{
	int i;
	printf(" 박수! \n");

	pthread_mutex_lock(&mtx);

	// 현재 쓰레드 PID를 가져온다.
	for(i = 0; i < clnt_cnt; i++)
		if(thread_pid[i] == getpid())
			cnt[i] += 1;
	longjmp(gogo, 1);
	pthread_mutex_unlock(&mtx);

	alarm(2);
}



void proc_msg(char *msg, int len, int k)
{
	int i;
	int cmp = atoi(msg);
	char smsg[64] = {0};

	pthread_mutex_lock(&mtx);
	// k는 현재 플레이어 넘버 +1, idx가 player라 보면됨.
	cnt[k] += 1;
	preNum++;	// 현재 진행중인 값.

	// 누구턴인지 -> (턴인사람 , 아닌사람->끝)
	// 데이터가 지행중인 값이랑 같은지


	if(data[k] > cmp)
		sprintf(smsg, "big than %d\n", cmp);
	else if(data[k] < cmp)
		sprintf(smsg, "less than %d\n", cmp);
	else if(setjmp(gogo))
		sprintf(smsg, "박수 \n");
	else
	{
		strcpy(smsg, "You win!\n");
		printf("cnt = %d\n", cnt[k]);
	}
	// 스트링에 가져다가 붙이는것. 
	// 사실 좋은 구조는 클라이언트한테 숫자 쏘고 클라이언트 종료되게 해야함.
	sprintf(smsg, "[%d] player Input Number: \n",k+1);
	write(clnt_socks[k], smsg, strlen(smsg));

	pthread_mutex_unlock(&mtx);
}




void *clnt_handler(void *arg)
{
	int clnt_sock = *((int *)arg);
	int str_len = 0, i;
	char msg[BUF_SIZE] = {0};
	char pattern[BUF_SIZE] = "Input Number: \n";

	// 
	signal(SIGALRM, sig_handler);
	signal(SIGINT, sig_handler2);

	// 쓰레드의 pid 값이 나온다 getpid 에서. 쓰레드를 통해 들어온거니까
	pthread_mutex_lock(&mtx);
	thread_pid[idx++] = getpid();
	i = idx - 1;
	printf("idx = %d\n",idx);
	printf("i = %d\n", i);

	// 락을 걸어준 것이다.
	write(clnt_socks[i], pattern, strlen(pattern));
	pthread_mutex_unlock(&mtx);

	alarm(2);
	//break point idx 2명이 들어와야 시작한다고 표시한것.
	while((str_len = read(clnt_sock, msg, sizeof(msg))) != 0 && idx >= 1)
	{
		// 잘 들어왔으니 알람을 초기화 한다.
		alarm(0);

		proc_msg(msg, str_len, i);

		alarm(2);
	}	


	clnt_cnt--;
	pthread_mutex_unlock(&mtx);
	close(clnt_sock);

	return NULL;	
}



int main(int argc , char **argv)
{
	int serv_sock, clnt_sock, fd;
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

	if(bind(serv_sock, (sap)&serv_addr, sizeof(serv_addr)) == -1)
		err_handler("bind() error");

	if(listen(serv_sock, 5) == -1)
		err_handler("listen() error");

	for(;;)
	{
		addr_size = sizeof(clnt_addr);
		// 클라이언트의 접근을 승인한다. 다음 클라이언트가 들어오기 전까지 블록한다.
		clnt_sock = accept(serv_sock, (sap)&clnt_addr, &addr_size);

		thread_pid[idx++] = getpid();
		// idx는 사람의 수 clnt_cnt 도 사람의 수.


		pthread_mutex_lock(&mtx);

		clnt_socks[clnt_cnt++] = clnt_sock; 
	
		pthread_mutex_unlock(&mtx);

		// 쓰레드에  전달되는 인자 (마지막꺼_fd값)
		pthread_create(&t_id, NULL, clnt_handler, (void *)&clnt_sock);
		// 떼어내다... 쓰레드 t_id는 식별자 혹은 id (cpu에 새로 할당됨)
		pthread_detach(t_id);
		printf("Connected Client IP: %s\n", inet_ntoa(clnt_addr.sin_addr));
	}
	//close(clnt_sock);
	close(serv_sock);

	return 0;
}





