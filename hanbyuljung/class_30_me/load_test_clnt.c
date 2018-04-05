#include "common.h"
#include <signal.h>
#include <setjmp.h>

jmp_buf env;
int tmp_sock;

void err_handler(char *msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

void read_proc(int sock, d *buf)
{
	for(;;)
	{
		int len = read(sock, buf, BUF_SIZE);

		if(!len)
			return;

		printf("msg from serv: %d, %f\n", buf->data, buf->fdata);
	}
}

void quit_proc(int signo)
{
	printf("Exited!\n");
	shutdown(tmp_sock, SHUT_WR);
	longjmp(env, 1);
}

void write_proc(int sock, d *buf)
{
	char msg[32] = {0};

	tmp_sock = sock;
	signal(SIGINT, quit_proc);

	for(;;)
	{
#if DEBUG
		fgets(msg, BUF_SIZE, stdin);
#endif
		buf->data = 3;
		buf->fdata = 7.7;

		write(sock, buf, sizeof(d));
	}
}

int main(int argc, char **argv)
{
	pid_t pid;
	int i, sock;
	si serv_addr;
	d struct_data;
	char buf[BUF_SIZE] = {0};

	if(argc != 3)
	{
		printf("use: %s <IP> <port>\n", argv[0]);
		exit(1);
	}

	sock = socket(PF_INET, SOCK_STREAM, 0);

	if(sock == -1)
		err_handler("socket() error");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));

	if(connect(sock, (sp)&serv_addr, sizeof(serv_addr)) == -1)
		err_handler("connect() error");
	else
		puts("Connected!\n");

	pid = fork();

	if(!pid)
	{
		int ret;

		if((ret = setjmp(env)) == 0)
			;
		else if(ret > 0)
			goto end;

		write_proc(sock, (d *)&struct_data);
	}
	else
		read_proc(sock, (d *)&struct_data);

end:
	close(sock);

	return 0;
}
