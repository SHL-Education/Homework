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
int thread_pid[MAX_CLNT];
int idx;
int cnt[MAX_CLNT];
// 
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
			cnt[i] += 1;

	pthread_mutex_unlock(&mtx);

	alarm(3);
}

void proc_msg(char *msg, int len, int k)
{
	int i;
	int cmp = atoi(msg);
	char smsg[64] = {0};

	pthread_mutex_lock(&mtx);

	cnt[k] += 1;

	if(data[k] > cmp)
		sprintf(smsg, "greater than %d\n", cmp);
	else if(data[k] < cmp)
		sprintf(smsg, "less than %d\n", cmp);
	else
	{
		strcpy(smsg, "You win!\n");
		printf("cnt = %d\n", cnt[k]);
	}
	// 스트링에 가져다가 붙이는것. 
	// 사실 좋은 구조는 클라이언트한테 숫자 쏘고 클라이언트 종료되게 해야함.
	strcat(smsg, "Input Number: \n");
	write(clnt_socks[k], smsg, strlen(smsg));

#if 0
	for(i = 0; i < clnt_cnt; i++)
	{
		if(data[i] > cmp)
			sprintf(smsg, "greater than %d\n", cmp);
		else if(data[i] < cmp)
			sprintf(smsg, "less than %d\n", cmp);
		else
			strcpy(smsg, "You win!\n");

		strcat(smsg, "Input Number: ");
		write(clnt_socks[i], smsg, strlen(smsg));
	}
#endif
	// 이제 언락을 시켜준다.
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

	// 쓰레드의 pid 값이 나온다 getpid 에서. 쓰레드를 통해 들어온거니까
	pthread_mutex_lock(&mtx);
	thread_pid[idx++] = getpid();
	i = idx - 1;
	printf("i = %d\n", i);
	// 아 쓰레드마다 자기가 관리하는 클라이언트의 썪이고 크리티컬 섹션이 나오지 않게 하기 위해
	// 락을 걸어준 것이다.
	write(clnt_socks[i], pattern, strlen(pattern));
	pthread_mutex_unlock(&mtx);

	alarm(3);

	while((str_len = read(clnt_sock, msg, sizeof(msg))) != 0)
	{
		// 잘 들어왔으니 알람을 초기화 한다.
		alarm(0);
		proc_msg(msg, str_len, i);
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
		// 클라이언트의 접근을 승인한다. 다음 클라이언트가 들어오기 전까지 블록한다.
		clnt_sock = accept(serv_sock, (sp)&clnt_addr, &addr_size);

		thread_pid[idx++] = getpid();

		// 여기서 lock을 건다. data가 꼬이지 말라고 하는것이다.
		// 소켓파일이 서버랑 클라이언트랑 공유메모리라서.
		// 이 순간부터 clnt_sock은 건들수 없다.
		pthread_mutex_lock(&mtx);
		data[clnt_cnt] = rand() % 3333 + 1;
		clnt_socks[clnt_cnt++] = clnt_sock;
		// 다 하고 나서  락을 풀어준다.
		pthread_mutex_unlock(&mtx);

		// 쓰레드에  전달되는 인자 (마지막꺼_fd값)
		pthread_create(&t_id, NULL, clnt_handler, (void *)&clnt_sock);
		// 떼어내다... 쓰레드 t_id는 식별자 혹은 id (cpu에 새로 할당됨)
		pthread_detach(t_id);
		printf("Connected Client IP: %s\n", inet_ntoa(clnt_addr.sin_addr));
	}

	close(serv_sock);

	return 0;
}
