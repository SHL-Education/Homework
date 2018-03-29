#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

typedef struct sockaddr_in si;
typedef struct sockaddr* sap;

void err_handler(char *msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}
int main(int argc, char **argv)
{
	int sock;
	int str_len;
	si serv_addr;
	char msg[32];

	if(argc != 3)
	{
		printf("use: %s <IP> <port> \n", argv[0]);
		exit(1);
	}

	// 네트워크 상의 파일 디스크립터를 받는다.
	// 파일의 오픈과 같은 역할이라고 보면 된다.
	sock = socket(PF_INET, SOCK_STREAM, 0);

	if(sock == -1)
		err_handler("socker() error");
	// 여기..... 부터 4줄이 tcp ip를
	// 서버어드레스를 초기화 하고 있다.
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	// 우리가 입력한 ip 주소가 들어감
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));// 포트번호가 들어감.

	// 자신의 파일 디스크립터를 가지고 서버에 연결함.
	if(connect(sock, (sap)&serv_addr, sizeof(serv_addr))==-1)
		err_handler("connect() error");
	// 서버 디스크립터가 받아온 정보에서 msg에 서버에서 받은것을 보냄.
	str_len = read(sock, msg, sizeof(msg) -1);
	if(str_len == -1)
		err_handler("read() error!");
	printf("msg from serv : %s\n", msg);
	close(sock);

	return 0;
}

