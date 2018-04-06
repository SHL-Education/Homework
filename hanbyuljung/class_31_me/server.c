#include "server.h"

#define BUF_SIZE		128
#define MAX_CLNT		256
#define SET_TIMES		6

int cnt[MAX_CLNT];
int clnt_cnt = 0;
int idx;
int clnt_socks[MAX_CLNT];
int thread_pid[MAX_CLNT];
double runtime=0.0;
double load_ratio;
int flag;

pthread_mutex_t mtx;
tv start, end;

void err_handler(char *msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}
double get_runtime(tv start, tv end)
{
	end.tv_usec = end.tv_usec - start.tv_usec;
	end.tv_sec = end.tv_sec - start.tv_sec;
	end.tv_usec += end.tv_sec * 1000000;

	if((end.tv_usec / 1000000.0) > 10)
	{
		gettimeofday(&start, NULL);
		//cnt[]
	}	

	//printf("runtime = %lf sec\n", end.tv_usec / 1000000.0);
	return end.tv_usec / 1000000.0;
}

int init_sock(void)
{
	int sock;

	sock = socket(PF_INET, SOCK_STREAM, 0);

	if(sock == -1)
		err_handler("socket() error!");

	return sock;
}

// serv = 0, clnt = 1
void init_sock_addr(si *serv_addr, int size, char **argv, int opt)
{
	memset(serv_addr, 0, size);
	serv_addr->sin_family = AF_INET;

	if(opt)
	{
		serv_addr->sin_addr.s_addr = inet_addr(argv[1]);
		serv_addr->sin_port = htons(atoi(argv[2]));
	}
	else
	{
		serv_addr->sin_addr.s_addr = htonl(INADDR_ANY);
		serv_addr->sin_port = htons(atoi(argv[1]));
	}
}

void post_sock(int serv_sock, si *serv_addr, int size)
{
	if(bind(serv_sock, (sap)serv_addr, size) == -1)
		err_handler("bind() error!");

	if(listen(serv_sock, 5) == -1)
		err_handler("listen() error!");
}


int accept_s(int serv_sock,si clnt_addr)
{
	int clnt_sock;
	socklen_t clnt_addr_size;
	clnt_addr_size = sizeof(clnt_addr);
	clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, 				&clnt_addr_size);

	if(clnt_sock == -1)
		err_handler("accept() err"); 

	return clnt_sock;
}

void send_msg(char *msg, int len)
{
	int i;
	pthread_mutex_lock(&mtx);

	for(i = 0; i<clnt_cnt; i++)
		write(clnt_socks[i], msg, len);
	
	pthread_mutex_unlock(&mtx);
}


void server_init(int argc , char **argv,int *serv_sock,int *clnt_sock, si *serv_addr,si *clnt_addr)
{

	char msg[] = "Hello Network Programming";
	if(argc != 2)
	{
		printf("use: %s <port>\n", argv[0]);
		exit(1);
	}
	// 소켓은 파일이다, 원격에 있는 파일을 말하는 것. 그래서 ipc를 쓴다.
	// 네트워크는 결국 원격의 ipc , 원격의 세마포어이다.
	// 소켓을 열어라 소크 스트림은  tcp 소켓을 사용한다는 뜻이다.
	// 리턴은 파일 디스크립터가 나온다.
	*serv_sock = socket(PF_INET, SOCK_STREAM, 0);

	if(*serv_sock == -1)
		err_handler("socket() error");

	// 서버 어드레스의  메모리를 한번 지워준다.
	memset(serv_addr, 0, sizeof(*serv_addr));
	serv_addr->sin_family =AF_INET; // 여기 패턴을 익혀야 한다.
	// 자신의 주소를 받겠다. 127.0.0.7 = 로컬호스트
	serv_addr->sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr->sin_port = htons(atoi(argv[1]));

	//스코프 바인딩. 서버의 ip 주소를 세팅한다. 127.0.0.7이됨
	if(bind(*serv_sock, (sap)serv_addr, sizeof(*serv_addr)) == -1)
		err_handler("bind() error");

	// 5명 까지 받겠다라는 뜻이다. 실제로 클라이언트  기다리는 곳이다.
	if(listen(*serv_sock, 20) == -1)
		err_handler("listen() error");

	
	// 밑으로 추가할 코드는 accept

	#if A
	for(;;)
	{
		addr_size = sizeof(*clnt_addr);
		clnt_sock = accept(serv_sock,(sap)&clnt_addr, &addr_size);
		

		pthread_mutex_lock(&mtx);
		ct->send_client[clnt_cnt] = 0;
		clnt_socks[clnt_cnt++] = clnt_sock;
		pthread_mutex_unlock(&mtx);

		printf("clnt_cnt (사람수) : %d\n", clnt_cnt);

		pthread_create(&t_id, NULL, clnt_handler, (void *) &clnt_sock);
		pthread_detach(t_id);
		printf("Connected Client IP: %s\n", inet_ntoa(clnt_addr.sin_addr));
	}
	close(serv_sock);

	#endif
}
// 블럭킹 서버 구현.
#if A
void *clnt_handler(void *arg)
{
	int clnt_sock = *((int *)arg);
	int str_len = 0, i;
	char msg[BUF_SIZE];
	char clnt_count[BUF_SIZE];
	i = clnt_cnt - 1;

	flag = 0;
	//tv start, end;


	pthread_mutex_lock(&mtx);
	thread_pid[idx++] = getpid();
	pthread_mutex_unlock(&mtx);

	gettimeofday(&start, NULL);
	while((str_len = read(clnt_sock , msg, sizeof(msg))) != 0){
		// 현재 말한 횟수 세는것은 한명만 된다.

		//ct->send_client[clnt_cnt-1] += 1;
		proc_msg(msg, str_len, i);
		send_msg(msg, str_len);

		// 끝나는 시간을 구함.
		gettimeofday(&end, NULL);

		//pthread_mutex_unlock(&mtx);

		runtime = get_runtime(start, end);
		if(runtime > 3)
		{
			gettimeofday(&start, NULL);
			cnt[i]=0;
		}
		load_ratio = cnt[i]/runtime;
		pthread_mutex_lock(&mtx);
		if(load_ratio > 5.7 || cnt[i]>15)
		{	
			flag++;
			// 여기서 나갈때 같이 나가버림.
			if(flag == 3){
				write(clnt_socks[i], "너 이제 진짜 말못함\n", 128);
				shutdown(clnt_socks[i], SHUT_WR);
				break ; 
			} 
			write(clnt_socks[i], "당신은 잠시 벙어리\n", 128);
			sleep(6);
			while(read(clnt_sock, msg, sizeof(msg)) > BUF_SIZE-1){
				memset(msg, 0, sizeof(msg));
			}
			memset(msg, 0, sizeof(msg));
			gettimeofday(&start, NULL);
			write(clnt_socks[i], "당신은 기적으로 말할 수 있게 되었습니다. \n", 128);
			cnt[i]=0;
			
		}	
		pthread_mutex_unlock(&mtx);

		printf("runtime = %lf sec\n", runtime);
		printf("{load_ratio} = %lf sec\n", load_ratio);

	}

	
	pthread_mutex_lock(&mtx);
	// 여기가 뭐하기 위한 건지 정확히 모르겠다.
	for(i = 0; i<clnt_cnt; i++){
		if(clnt_sock == clnt_socks[i])
		{
			while(i++ < clnt_cnt-1)
				clnt_socks[i] = clnt_socks[i+1];
			break;
		}
	}

	clnt_cnt --;
	pthread_mutex_unlock(&mtx);
	close(clnt_sock);

	return NULL;
}
#endif
