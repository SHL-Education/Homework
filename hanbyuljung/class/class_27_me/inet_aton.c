#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

// 호스트(로컬) 네트워크 호스트(로컬)
//     리틀		   빅		빅
//	   빅		   빅		리틀

// 네트워크는 무조건 빅으로 들어온다.

//osi7계층, tcp/ip에 헤더에 리틀인지 빅인지에 대한 정보가 있다.

typedef struct sockaddr_in si;

void err_handler(char *msg)
{
	write(2, msg, strlen(msg));
	exit(1);
}

int main(int argc, char **argv)
{

	char *addr = "127.124.73.31";
	si addr_inet;

	if(!inet_aton(addr, &addr_inet.sin_addr))
	err_handler("Converslon Error!");
	else
	printf("Network Ordered integer Addr:%#x\n", addr_inet.sin_addr.s_addr);

	return 0;
}


