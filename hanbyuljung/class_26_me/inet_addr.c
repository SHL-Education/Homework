// 주소체계라고 한다. big 엔디안 little 엔디안... 
// 서로 같은 규격으로 맞추지 않으면 꼬인다.
// 네트워크 형식에 맞게 변경을 시킨다.

// 처음이 0 이라서 굳이 출력이 안되는 것이다. 그래서 09050703
// 가 아니라 

#include<stdio.h>
#include<arpa/inet.h>

int main(int argc, char **argv)
{
	 char *addr1 = "3.7.5.9";
	 char *addr2 = "1.3.5.7";

	 unsigned long conv_addr = inet_addr(addr1);
	 if(conv_addr == INADDR_NONE)
		 printf("Error!\n");
	 else
		 printf("Network Ordered Interger Addr: %#lx\n", conv_addr);

	 conv_addr = inet_addr(addr2);
	if(conv_addr == INADDR_NONE)
		printf("Error!\n");
	else
		printf("Network Ordered Integer Addr:%#lx\n",conv_addr);
	return 0;
}
