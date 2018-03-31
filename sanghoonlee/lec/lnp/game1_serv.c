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
	alarm(3);
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

void start_game(int data, int sock)
{
	char buf[32] = {0};
	char msg[128] = {0};
	char out[64] = "숫자를 맞춰봐: ";
	bool fin;
	int i, cmp, nr;

	signal(SIGALRM, sig_handler);

	for(;;)
	{
		write(sock, out, strlen(out));
		alarm(3);
		//read(0, buf, sizeof(buf));
		nr = read(sock, buf, sizeof(buf));
		buf[nr - 1] = '\0';
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
			{
				sprintf(msg, "%d 보다 크다\n", cmp);
				msg[strlen(msg)] = '\0';
				write(sock, msg, strlen(msg));
				//printf("%d 보다 크다\n", cmp);
			}
			else
			{
				sprintf(msg, "%d 보다 작다\n", cmp);
				msg[strlen(msg)] = '\0';
				write(sock, msg, strlen(msg));
				//printf("%d 보다 작다\n", cmp);
			}
		}
	}
}

void err_handler(char *msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

void child_proc(int sig)
{
	pid_t pid;
	int status;
	pid = waitpid(-1, &status, WNOHANG);
	printf("Removed proc id: %d\n", pid);
}

int main(int argc, char **argv)
{
	//pid_t pid[5] = {0};
	pid_t pid;
	int status;

	int serv_sock, clnt_sock;
	char opinfo[BUF_SIZE];

	int result, opnd_cnt, i;
	int recv_cnt, recv_len;

	si serv_addr, clnt_addr;
	socklen_t clnt_addr_size;

	struct sigaction act;
	int state;

	if(argc != 2)
	{
		printf("use: %s <port>\n", argv[0]);
		exit(1);
	}

	act.sa_handler = child_proc;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	state = sigaction(SIGCHLD, &act, 0);

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

	for(i = 0; i < 5; i++)
	{
		clnt_addr_size = sizeof(clnt_addr);
		clnt_sock = accept(serv_sock, (sap)&clnt_addr, &clnt_addr_size);

		pid = fork();

		if(pid == 0)
		{
			int data;

			srand(time(NULL));

			close(serv_sock);

			make_game(&data);
			printf("data = %d\n", data);
			start_game(data, clnt_sock);

			printf("Client Disconnected\n");

#if 0
			for(;;)
			{
				//write(clnt_sock, buf, strlen(buf));

				glob_cnt++;
				if(glob_cnt > 10)
					break;
			}
#endif

			close(clnt_sock);

			return 0;
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
		else
			close(clnt_sock);

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
