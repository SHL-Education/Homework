#include <signal.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <sys/socket.h>

typedef struct sockaddr_in	si;
typedef struct sockaddr *	sp;

typedef struct __q{
	int data;
	struct __q *link;
} q;

#define BUF_SIZE			32

void err_handler(char *msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

void read_cproc(int sig)
{
	pid_t pid;
	int status;
	pid = waitpid(-1, &status, WNOHANG);
	printf("Removed proc id: %d\n", pid);
}

q *get_node(void)
{
	q *tmp;
	tmp = (q *)malloc(sizeof(q));
	tmp->link = NULL;
	return tmp;
}

bool enqueue(q **head, int data)
{
	if(!(*head))
	{
		*head = get_node();
		(*head)->data = data;
		return true;
	}

	return enqueue(&(*head)->link, data);
}

void print_queue(q *head)
{
	q *tmp = head;

	while(tmp)
	{
		printf("data = %d\n", tmp->data);
		tmp = tmp->link;
	}
}

int main(int argc, char **argv)
{
	int serv_sock, clnt_sock, len, state;
	char buf[BUF_SIZE] = {0};
	si serv_addr, clnt_addr;
	struct sigaction act;
	socklen_t addr_size;
	q *head = NULL;
	pid_t pid;
	
	if(argc != 2)
	{
		printf("use: %s <port>\n", argv[0]);
		exit(1);
	}

	act.sa_handler = read_cproc;
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

	if(bind(serv_sock, (sp)&serv_addr, sizeof(serv_addr)) == -1)
		err_handler("bind() error");

	if(listen(serv_sock, 5) == -1)
		err_handler("listen() error");

	for(;;)
	{
		addr_size = sizeof(clnt_addr);
		clnt_sock = accept(serv_sock, (sp)&clnt_addr, &addr_size);

		if(clnt_sock == -1)
			continue;
		else
			puts("New Client Connected!\n");

		pid = fork();

		if(pid == -1)
		{
			close(clnt_sock);
			continue;
		}

		if(!pid)
		{
			int data;
			bool test;
			close(serv_sock);

			while((len = read(clnt_sock, buf, BUF_SIZE)) != 0)
			{
				data = atoi(buf);
				test = enqueue(&head, data);
				printf("Now printing Queue\n");
				print_queue(head);

				if(test)
				{
					char msg[32] = "success\n";
					write(clnt_sock, msg, strlen(msg));
				}
				else
				{
					char msg[32] = "failure\n";
					write(clnt_sock, msg, strlen(msg));
				}
			}

			close(clnt_sock);
			puts("Client Disconnected!\n");
			return 0;
		}
		else
			close(clnt_sock);
	}
	close(serv_sock);

	return 0;
}
