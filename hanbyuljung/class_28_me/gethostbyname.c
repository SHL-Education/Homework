#include<stdio.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<stdlib.h>


void err_handler(char *msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

int main(int argc ,char **argv)
{
	int i;
	struct hostent *host;

	if(argc != 2)
	{
		printf("use : %s <poer>\n", argv[0]);
		exit(10);
	}
	
	host = gethostbyname(argv[1]);

	if(!host)
		err_handler("gethost ... error !");

	printf("Official Name : %s\n", host ->h_name);

	for(i = 0; host->h_aliases[i] ; i++)
		printf("aliases %d : %s\n" , i+1, host -> h_aliases[i]);

	printf("Address Type: %s\n", (host->h_addrtype == AF_INET) ? "AF_INET" :"AF_INETS");

	for(i= 0 ; host->h_addr_list[i]; i++)
		printf("IP Addr %d:%s \n", i+1, inet_ntoa(*(struct in_addr *)host->h_addr_list[i]));

	return 0;
}
