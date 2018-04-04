#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netdb.h>

typedef struct sockaddr_in	si;

void err_handler(char *msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

int main(int argc, char **argv)
{
	int i ;
	si addr ;
	struct hostent *host;

	if(argc != 2)
	{
		printf("use: %s <port>\n", argv[0]);
		exit(1);
	}
	memset(&addr, 0, sizeof(addr));
	addr.sin_addr.s_addr = inet_addr(argv[1]);
	host = gethostbyaddr((char *)&addr.sin_addr, 4, AF_INET);

	if(!host)
		err_handler("gethost error!");

	
	printf("Official Name : %s\n",host->h_name);
	for(i = 0; host->h_aliases[i]; i++)
		printf("aliases %d:%s \n", i+1 , host->h_aliases[i]);

	printf("Address Type: %s\n", (host->h_addrtype == AF_INET) ?"AF_INET" : "AF_INET6");

	for(i = 0 ; host->h_addr_list[i]; i++)
		printf("IP Addr %d :%s\n", i+1,
		inet_ntoa(*(struct in_addr *)host->h_addr_list[i]));
	return 0;
}


// 방화벽이 있고 하면 안될 수 hosterr 라고 뜰수 있다.
