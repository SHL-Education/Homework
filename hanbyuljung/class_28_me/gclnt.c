#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>

#define BUF_SIZE		128

typedef struct sockaddr_in	si;
typedef struct sockaddr *	sp;

char msg[BUF_SIZE];

void err_handler(char *msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

// pthead_creat의 마지막인자는 여기로 들어온다. 여러개 보낼려면 구조체 형으로 보내야한다.
// 3번째 인자에는 void * 형으로 들어와야한다... 어떤게 올지 모르니까.
// 검색 속도를 올릴려면 , 예를 들어 이진트리를 병렬 검색을 한다
void *send_msg(void *arg)
{
	int sock = *((int *)arg);
	char msg[BUF_SIZE];

	for(;;)
	{
		// 무한루프를 돌면서 계속 읽고 전송해 준다.
		fgets(msg, BUF_SIZE, stdin);
		write(sock, msg, strlen(msg));
	}

	return NULL;
}

void *recv_msg(void *arg)
{
	int sock = *((int *)arg);
	char msg[BUF_SIZE];
	int str_len;

	for(;;)
	{
		// 서버로 부터 받아서 
		str_len = read(sock, msg, BUF_SIZE - 1);
		// 0으로 해주는 이유는 먼저 긴게 들어오고 나중에 짧은게 들어올때 덮어씌면서 뒤가 남음.
		// memset을 해주는게 좋지만 널문자를 끝맺음을 함으로 동작에 이득을 취한다.
		msg[str_len] = 0;
		// 모니터의 출력을 한다.
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

	// 커넥트 하는 순간 어셉트가 동작한다.
	// 위에서 설정한 (포트와 주소 정보(serv_adr)) 를 가지고 connect를 시도한다.
	if(connect(sock, (sp)&serv_addr, sizeof(serv_addr)) == -1)
		err_handler("connect() error");

	// 송신과 수신을 분리하기 위해서 한다. fork랑 비슷하다.
	// 전송.
	pthread_create(&snd_thread, NULL, send_msg, (void *)&sock);
	// 수신.
	pthread_create(&rcv_thread, NULL, recv_msg, (void *)&sock);
	// 본격적인 구동은 join을 할때. 더이상 센드, 혹은 보낼게 없거나 하면 멈춤.
	pthread_join(snd_thread, &thread_ret);
	pthread_join(rcv_thread, &thread_ret);

	close(sock);

	return 0;
}
