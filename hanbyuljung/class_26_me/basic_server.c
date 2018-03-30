#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

// sockaddr_in 는 ip 와 포트번호를 담아오는 구조체
typedef struct sockaddr_in si;
typedef struct sockaddr *sap;

void err_handler(char *msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

int main(int argc, char **argv)
{
	int serv_sock;
	int clnt_sock;

	si serv_addr;
	si clnt_addr;
	socklen_t clnt_addr_size;

	char msg[] = "Hello Network Programming";
	if(argc != 2)
	{
		printf("use: %s <port>\n", argv[0]);
		exit(1);
	}
	// 소켓은 파일이다, 원격에 있는 파일을 말하는 것. 그래서 ipc를 쓴다.
	// 네트워크는 결국 원격의 ipc , 원격의 세마포어이다.
	// 소켓을 열어라 소크 스트림은  tcp 소켓을 사용한다는 뜻이다.
	// 리턴은 파일 디스크립터가 나온다.
	serv_sock = socket(PF_INET, SOCK_STREAM, 0);

	if(serv_sock == -1)
		err_handler("socket() error");

	// 서버 어드레스의  메모리를 한번 지워준다.
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family =AF_INET; // 여기 패턴을 익혀야 한다.
	// 자신의 주소를 받겠다. 127.0.0.7 = 로컬호스트
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	//스코프 바인딩. 서버의 ip 주소를 세팅한다. 127.0.0.7이됨
	if(bind(serv_sock, (sap)&serv_addr, sizeof(serv_addr)) == -1)
		err_handler("bind() error");

	// 5명 까지 받겠다라는 뜻이다. 실제로 클라이언트  기다리는 곳이다.
	if(listen(serv_sock, 5) == -1)
		err_handler("listen() error");

	clnt_addr_size = sizeof(clnt_addr);
	// accept는 서버 소켓이 클라이언트의 실제 접속 허용을 해주는 곳이다.
	clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size);

	if(clnt_sock == -1)
		err_handler("accept() error");
	// 원격에 있는 클라이언트에게 롸이트를 한다.
	write(clnt_sock, msg, sizeof(msg));
	close(clnt_sock);
	close(serv_sock);

	return 0;
}

