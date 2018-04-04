#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

typedef struct sockaddr_in	si;
typedef struct sockaddr *	sap;

#define BUF_SIZE		32
#define EMPTY			0

typedef struct __stack
{
	int data; 
	struct __stack *link;
	//int fdata[0];
}Stack;


Stack *get_node()
{
	Stack *tmp;
	tmp = (Stack *)malloc(sizeof(Stack));
	tmp-> link = 0;
	return tmp ;
}
void err_handler(char *msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

void push(Stack **top, int data)
{
	Stack *tmp;
	tmp = *top;
	*top = get_node();
	(*top) -> data = data;
	(*top) -> link = tmp;
	
}
int pop(Stack **top)
{
	Stack *tmp;
	int num;
	*top = get_node();
	tmp = *top;
	if(tmp == NULL){
			printf("값이 없다\n");
			return 0;
	}
	if((*top)){
        	num = (*top)-> data;
		*top = (*top)->link;
	}
	free(tmp);
	return num;
}

int main(int argc, char **argv)
{
	pid_t pid;
	int i, sock;
	si serv_addr;
	char buf[1024] = {0};
	char smsg[256];

	Stack *top=get_node();
	

	if(argc != 3)
	{
		printf("use: %s <IP> <port>\n", argv[0]);
		exit(1);
	}


	if(sock == -1)
		err_handler("socket() error");

	sock = socket(PF_INET, SOCK_STREAM, 0);


	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));

	// 커넥트 하는 순간 어셉트가 동작한다.
	// 위에서 설정한 (포트와 주소 정보(serv_adr)) 를 가지고 connect를 시도한다.
	if(connect(sock, (sap)&serv_addr, sizeof(serv_addr)) == -1)
		err_handler("connect() error");

	else
		puts("Connected .....");
	
	read(sock, (Stack *)top, sizeof(buf));

	if(!pid){
		
		//top = (Stack *)buf;
//		printf("%d\n", pop(&top));
//		printf("%d\n", pop(&top));
//		printf("%d\n", pop(&top));
		sprintf(smsg,"%d\n", pop(&top));
		printf("%s", smsg);
		write(sock , smsg, sizeof(Stack));
		sprintf(smsg,"%d\n", pop(&top));
		printf("%s", smsg);
		write(sock , smsg, sizeof(Stack));
		sprintf(smsg,"%d\n", pop(&top));
		printf("%s", smsg);
		write(sock , smsg, sizeof(Stack));
//		sprintf(smsg,"%d\n", pop(&top));
//		write(clnt_sock , (Stack *)&top, sizeof(Stack));
	}
	else
		//read_routine(sock, (Stack *)buf);

	close(sock);

	return 0;
}
