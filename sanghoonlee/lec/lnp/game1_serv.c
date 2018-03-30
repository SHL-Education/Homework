/* For Network */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

/* For System */
#include <time.h>
#include <fcntl.h>
#include <signal.h>
#include <stdbool.h>
#include <sys/wait.h>

typedef struct sockaddr_in	si;
typedef struct sockaddr *	sap;

#define BUF_SIZE		1024
#define OPSZ			4

int glob_cnt;

void sig_handler(int signo)
{
	printf("Time Over\n");
	glob_cnt++;
}

void make_game(int *data)
{
	*data = rand() % 3333 + 1;
}

bool check_correct(int data, int cmp)
{
	if(data == cmp)
		return true;
	else
		return false;
}

void start_game(int data)
{
	char buf[32] = {0};
	bool fin;
	int i, cmp;

	for(;;)
	{
		signal(SIGALRM, sig_handler);
		alarm(1);
		read(0, buf, sizeof(buf));
		alarm(0);
		cmp = atoi(buf);

		fin = check_correct(data, cmp);

		if(fin)
		{
			break;
		}
		else
		{
			glob_cnt++;
			if(data > cmp)
				printf("%d 보다 크다\n", cmp);
			else
				printf("%d 보다 작다\n", cmp);
		}
	}
}

void err_handler(char *msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

int calculate(int opnum, int *opnds, char op)
{
	int result = opnds[0], i;

	switch(op)
	{
		case '+':
			for(i = 1; i < opnum; i++)
				result += opnds[i];
			break;
		case '-':
			for(i = 1; i < opnum; i++)
				result -= opnds[i];
			break;
		case '*':
			for(i = 1; i < opnum; i++)
				result *= opnds[i];
			break;
	}

	return result;
}

int main(int argc, char **argv)
{
	pid_t pid[5] = {0};
	int status;

	int serv_sock, clnt_sock;
	char opinfo[BUF_SIZE];

	int result, opnd_cnt, i;
	int recv_cnt, recv_len;

	si serv_addr, clnt_addr;
	socklen_t clnt_addr_size;

	if(argc != 2)
	{
		printf("use: %s <port>\n", argv[0]);
		exit(1);
	}

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

	clnt_addr_size = sizeof(clnt_addr);

	//signal();

	for(i = 0; i < 5; i++)
	{
		pid[i] = fork();

		if(pid[i] > 0)
			wait(&status);
		else
		{
			int data;
			char buf[32] = "숫자를 맞춰봐!\n";

			srand(time(NULL));
			clnt_sock = accept(serv_sock, (sap)&clnt_addr, &clnt_addr_size);
			make_game(&data);

			for(;;)
			{
				write(clnt_sock, buf, strlen(buf));
				glob_cnt++;
				if(glob_cnt > 10)
					break;
			}

			close(clnt_sock);
#if 0
			opnd_cnt = 0;
			clnt_sock = accept(serv_sock, (sap)&clnt_addr, &clnt_addr_size);
			read(clnt_sock, &opnd_cnt, 1);

			recv_len = 0;

			while((opnd_cnt * OPSZ + 1) > recv_len)
			{
				recv_cnt = read(clnt_sock, &opinfo[recv_len], BUF_SIZE - 1);
				recv_len += recv_cnt;
			}

			result = calculate(opnd_cnt, (int *)opinfo, opinfo[recv_len - 1]);
			write(clnt_sock, (char *)&result, sizeof(result));

			close(clnt_sock);
#endif
		}

	}
#if 0
	for(i = 0; i < 5; i++)
	{
		opnd_cnt = 0;
		clnt_sock = accept(serv_sock, (sap)&clnt_addr, &clnt_addr_size);
		read(clnt_sock, &opnd_cnt, 1);

		recv_len = 0;

		while((opnd_cnt * OPSZ + 1) > recv_len)
		{
			recv_cnt = read(clnt_sock, &opinfo[recv_len], BUF_SIZE - 1);
			recv_len += recv_cnt;
		}

		result = calculate(opnd_cnt, (int *)opinfo, opinfo[recv_len - 1]);
		write(clnt_sock, (char *)&result, sizeof(result));

		close(clnt_sock);
	}
#endif

	close(serv_sock);

	return 0;
}
