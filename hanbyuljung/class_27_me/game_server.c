#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<unistd.h>
#include<malloc.h>
#include<time.h>

#define BUF_SIZE 1024
#define OPSZ		4
#define EMPTY		0

typedef struct sockaddr_in si;
typedef struct sockaddr *sap;

int flag=0;
int cnt=0;
int serv_sock, clnt_sock;
// 사이즈 크기가 4개라는 뜻으로 씀
void err_handler(char *msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}
	
// 카운트를 받아서 카운트를 1증가한다.
void my_sig(int signo)
{
	//printf("입력 시간이 늦었습니다 카운트 수를 올립니다!\n");
	char inputtime[]="입력 시간이 늦었습니다 카운트 수를 올립니다!\n";
	write(clnt_sock, inputtime, sizeof(inputtime));
	cnt++;
	alarm(3);
	//exit(0);
}

char game(int clnt_sock,int random,char *opnds)
{
	char buf[1024];
	int ret;
	int setnum;
	//if(flag == 0){
		char up[]="너 높다";
		char down[] = "너 낮다";
		char correct[]= "맞추셨습니다! 술 드세요!!!\n";
		char start[] = "술게임을 시작합니다.\n내가 내는 번호를 맞춰 보세요!\n";

		signal(SIGALRM, my_sig);

		write(clnt_sock, start, sizeof(start));

		int i=0;
		flag = 1;
	//}
	// 입력 시간을 3초로 해준다.
	alarm(3);
	setnum = atoi(opnds);
	
	if(setnum == random){
		// 여기서 알람을 끄거나 마지막 부분에 끝난다고 해주어야함.
		write(clnt_sock, correct, sizeof(start));
		// 누가 1등인지 알아맞추는 함수를 만든다.

		// 그리고 꺼준다.
		close(clnt_sock);
	}
	else if(setnum > random){	
		write(clnt_sock, up, sizeof(start));
	}
	else if(setnum < random){
		write(clnt_sock, down, sizeof(start));
	}
	//카운트를 증가해 준다.
	return ++cnt;
	//}
}

int main(int argc, char **argv)
{
	
	char opinfo[BUF_SIZE];

	int opnd_cnt, i;
	char result;
	int recv_cnt , recv_len;
	si serv_addr, clnt_addr;
	socklen_t clnt_addr_size;

	int random;
	int cnt =0;
	char buf[1024];

	srand(time(NULL));
	random = rand()% 3333 +1;

//	game(random);

///////////////////////////////////////////////////////////////////////////////////////
	if(argc != 2)
	{
		printf("use: %s <port>\n",argv[0]);
		exit(1);
	}
	serv_sock = socket(PF_INET, SOCK_STREAM, 0);

	if(serv_sock == -1)
		err_handler("socket() error");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	if(bind(serv_sock, (sap) &serv_addr, sizeof(serv_addr)) == -1)
		err_handler("bind() error");

	if(listen(serv_sock, 5) == -1)
		err_handler("listen() error");

	clnt_addr_size = sizeof(clnt_addr);
///////////////////////////////////////////////////////////////////////////////////////
	// 여러명이 접속 할 수 있으니까 반복문으로 했다.??
	while(1)
	{
		opnd_cnt = 0;
		clnt_sock = accept(serv_sock, (sap)&clnt_addr, &clnt_addr_size);
		// 여기에 포크를 넣어야한다.

		// 여기는 부모니쪽이다.if로 나눠줘야함.
		read(clnt_sock, buf, sizeof(buf)); // 읽을 갯수를 받음.

		recv_len = 0;
		// OPSZ op의 크기, 더블을 연산 하면 8로 해야함.
		// 여러명이 접속할 수 있으니까 반복문
		//while((opnd_cnt *OPSZ +1) >recv_len)
		//{
		//	recv_cnt = read(clnt_sock, &opinfo[recv_len], BUF_SIZE -1);
		//	recv_len += recv_cnt;
		//}

		// 게임 함수가 return을 up 인지 down 인지 맞는지 리턴한다.
		// opnd_cnt는 받은 내용임...
		result = game(clnt_sock,random, buf);
		write(clnt_sock, &result, sizeof(result));

		// 여기는 맞았을 때만 클라이언트를 끝낸다고 해야한다.
		//close(clnt_sock);

	}
	close(serv_sock);

	return 0;
}
