#include "common.h"
#include "init_sock.h"

int main(int argc, char **argv)
{
	int sock, len;
	si serv_addr;
	char msg[32] = {0};

	if(argc != 3)
	{
		printf("use: %s <ip> <port>\n", argv[0]);
		exit(1);
	}

	sock = init_sock();
	init_sock_addr(&serv_addr, sizeof(serv_addr), argv, 1);

	if(connect(sock, (sp)&serv_addr, sizeof(serv_addr)) == -1)
		err_handler("connect() error!");

	len = read(sock, msg, sizeof(msg) - 1);

	if(len == -1)
		err_handler("read() error!");

	printf("msg from serv: %s\n", msg);
	close(sock);

	return 0;
}
