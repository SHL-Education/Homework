#include<stdio.h>
#include<arpa/inet.h>

int main(void)
{
	// 2바이트
	unsigned short host_port = 0x5678;
	unsigned short net_port ;
	// 4바이트
	unsigned long host_addr = 0x87654321;
	unsigned long net_addr;

	net_port = htons(host_port);
	net_addr = htonl(host_addr);
	//
	// 리틀엔디안을 메로리가 실제 배치되는 대로 배치가 바뀐다.크로스매칭.
	// 서로 다른 인디안 끼리 정보를 받으면 정보가 꼬이니
	// 같은 포멧으로 저장하는 거임
	printf("Host OrderedPort: %#x\n", host_port);
	printf("Network Ordered Port: %#x\n", net_port);
	printf("Host Ordered Address: %#lx\n",host_addr);
	printf("Network Ordered Address: %#lx\n", net_addr);
	return 0;
}
