#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>

#define BUF_SIZE		128
#define NAME_SIZE		32

typedef struct sockaddr_in	si;
typedef struct sockaddr *	sp;

char name[NAME_SIZE] = "[내가이긴다]";
char msg[2048];

void err_handler(char *msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

void make_rand_str(char *tmp)
{
	int i, end = rand() % 7 + 3;

	for(i = 0; i < end; i++)
		tmp[i] = rand() % 26 + 65;
}

void *send_msg(void *arg)
{
	int sock = *((int *)arg);
	char msg2[] = "https://kr.battle.net/heroes/ko/  <<== 지금 당장 접속하세요!!\n";
	srand(time(NULL));

	char tmp1[32] = {0};

	for(;;)
	{
#if PASSIVE
		fgets(msg, BUF_SIZE, stdin);

		write(sock, msg, strlen(msg));
#endif
#if ATTACK
		make_rand_str(tmp1);

		printf("%s\n", msg);
		sprintf(msg, "%s %s %s", name, tmp1, msg2);
		printf("tmp1 = %s\n", tmp1);
		write(sock, msg, strlen(msg));
		sleep(5);
#endif
	}

	return NULL;
}

void *recv_msg(void *arg)
{
	int sock = *((int *)arg);
	char msg[NAME_SIZE + 2048];
	int str_len;

	for(;;)
	{
		str_len = read(sock, msg, NAME_SIZE + 2047);

		msg[str_len] = 0;
		fputs(msg, stdout);
	}

	return NULL;
}

int main(int argc, char **argv)
{
	int sock;
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
