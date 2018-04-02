#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <setjmp.h>
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
int thread_pid[MAX_CLNT];
int idx;
int cnt[MAX_CLNT];
pthread_mutex_t mtx;

jmp_buf env;

void err_handler(char *msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

void sig_handler(int signo)
{
	int i;
	char smsg[32] = {0};

	printf("Time Over!\n");
	alarm(0);

	strcpy(smsg, "You Lose\n");
	write(clnt_socks[0], smsg, strlen(smsg));
	longjmp(env, 1);
}

bool check_369(char *msg, int cnt)
{
	int i, loop, cnt_3 = 0, tmp = cnt;

	for(i = 1; i <= 4; i++)
	{
		if(cnt / pow(10, i))
			;
		else
			break;
	}

	printf("자릿수 몇 개 = %d\n", i);

	// 각 자리수로 나눈 몫을 파악해야함
	for(loop = i - 1; loop > 0; loop--)
	{
		if(!((tmp % (pow(10, loop))) % 3))
		{
			cnt_3++;
			tmp /= 10;
		}
	}
}

void proc_msg(char *msg, int len, int cnt)
{
	int i;
	int cmp;
	bool test;
	char smsg[64] = {0};

	if(strcmp(msg, "c"))
		cmp = atoi(msg);

	test = check_369(msg, cnt);

	if(test)
	{
		strcpy(smsg, "Input Next\n");
		write(clnt_sock, smsg, strlen(smsg));
	}
	else
	{
		strcpy(smsg, "You Lose\n");
		write(clnt_sock, smsg, strlen(smsg));
		longjmp(env, 1);
	}
}

void *game_start(void *arg)
{
	int len, ret, cnt = 0;
	char msg[32] = {0};
	int clnt_sock = *((int *)arg);
	char pattern[BUF_SIZE] = "Let's start 369 Game!\n";

	signal(SIGALRM, alarm_handler);

	write(clnt_sock, pattern, strlen(pattern));

	alarm(2);

	if((ret = setjmp(env)) == 0)
		;
	else
		goto fin;

	while((len = read(clnt_sock, msg, sizeof(msg))) != 0)
	{
		alarm(0);
		cnt++;
		proc_msg(msg, str_len, cnt);
		alarm(2);
	}

fin:
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

	addr_size = sizeof(clnt_addr);
	clnt_sock = accept(serv_sock, (sp)&clnt_addr, &addr_size);

	clnt_socks[0] = clnt_sock;

	pthread_create(&t_id, NULL, game_start, (void *)&clnt_sock);
	pthread_join(t_id);
	printf("Connected IP: %s\n", inet_ntoa(clnt_addr.sin_addr));

#if 0
	for(;;)
	{
		addr_size = sizeof(clnt_addr);
		clnt_sock = accept(serv_sock, (sp)&clnt_addr, &addr_size);

		thread_pid[idx++] = getpid();

		pthread_mutex_lock(&mtx);
		data[clnt_cnt] = rand() % 3333 + 1;
		clnt_socks[clnt_cnt++] = clnt_sock;
		pthread_mutex_unlock(&mtx);

		pthread_create(&t_id, NULL, clnt_handler, (void *)&clnt_sock);
		pthread_detach(t_id);
		printf("Connected Client IP: %s\n", inet_ntoa(clnt_addr.sin_addr));
	}
#endif

	close(serv_sock);

	return 0;
}
