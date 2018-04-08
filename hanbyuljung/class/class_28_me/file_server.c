#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

typedef struct sockaddr_in si;
typedef struct sockaddr * sap;

#define BUF_SIZE		32

void err_handler(char *msg)
{
	fputs(msg, stderr);
	fputc('\n' , stderr);
	exit(1);
}

int main(int argc, char **argv)
{

	int serv_sock, clnt_sock, id,fd;
	char buf[BUF_SIZE] = {0};
	int read_cnt ;

	si serv_addr, clnt_addr;
	socklen_t clnt_addr_size;

	if(argc != 2)
	{
		printf("use:%s <port>\n", argv[0]);
		exit(1);
	}

	// 파일 서버를 열고 있다. 만약 뭔가를 전송 하고 싶으면 여기를 바꾸면 됩니다.
	fd = open("file_server.c" ,O_RDONLY);
	serv_sock = socket(PF_INET, SOCK_STREAM , 0);

	if(serv_sock == -1)
		err_handler("socket() error");

	// 네트워크를 저장하는 순서가 다르다 Byte order(little endian , big endian)
	// 다른 컴퓨터와 통신을 이루려면 이것을 맞추어야 한다.
	// host to network short (htons)
	// host to network long (htonl)
	// serv_addr.sin_addr.s_addr 은 INADDR_ANY 가 자신의 주소를 컴터가 찾아준다.(127.0.0.1)
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET; // AF_INET (IPv4 로 고정)
	serv_addr.sin_port = htons(atoi(argv[1]));
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	// fd(serv_sock), 연결요구 받기전 자신의 주소를 지정해 클라이언트의 연결 요구를 이곳으로 오게한다.
	if(bind(serv_sock, (sap)&serv_addr, sizeof(serv_addr)) == -1)
		err_handler("bind() error");

	// 보통 연결의 최대 값은 5이다 backlog 에 accept() 한수 실행시 누적되는 연결 수를 알 수 있다.
	// listen을 통해서 여러 클라이언트를 준비한다.
	if(listen(serv_sock, 5) == -1)
		err_handler("listen() error");

	clnt_addr_size = sizeof(clnt_addr);

	// 연결이 성공된 clnt_addr(주소) 를 받아 저장한다. 블록킹 함수로 연결을 기다린다.
	// 클라이언트와 소통을 하기 위해 자동을 소켓을 생성한다. (클라이언트쪽 소켓)
	// 
	clnt_sock = accept(serv_sock , (sap)&clnt_addr, &clnt_addr_size);

	for(;;)
	{
		// 클라이언트에게 글을 받을 때까지 대기 한다. *블록상태...
		read_cnt = read(fd, buf, BUF_SIZE);

		if(read_cnt < BUF_SIZE)
		{
			write(clnt_sock ,buf, read_cnt);
			break;
		}

		write(clnt_sock, buf , BUF_SIZE);
	}

	shutdown(clnt_sock, SHUT_WR);
	read(clnt_sock ,buf, BUF_SIZE);
	printf("msg from client: %s\n", buf);

	close(fd);
	close(clnt_sock);
	close(serv_sock);
	return 0;
}





