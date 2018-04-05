#include "init_sock.h"

int main(int argc, char **argv)
{
	int serv_sock, clnt_sock;
	si serv_addr, clnt_addr;
	socklen_t clnt_addr_size;
	char msg[] = "Hello Network Programming";

	if(argc != 2)
	{
		printf("use: %s <port>\n", argv[0]);
		exit(1);
	}

	serv_sock = init_sock();
	init_sock_addr(&serv_addr, sizeof(serv_addr), argv, 0);
	post_sock(serv_sock, &serv_addr, sizeof(serv_addr));

	clnt_addr_size = sizeof(clnt_addr);
	clnt_sock = accept(serv_sock, (sp)&clnt_addr, &clnt_addr_size);

	if(clnt_sock == -1)
		err_handler("accept() error");

	write(clnt_sock, msg, sizeof(msg));

	close(clnt_sock);
	close(serv_sock);

	return 0;
}
