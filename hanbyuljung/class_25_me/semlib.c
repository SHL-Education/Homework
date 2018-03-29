#include "sem.h"

int CreateSEM(key_t semkey)
{
	int status = 0,semid=-1;

	// IPC = inter process communication 프로세스 여러개가 공유를 한다.
	// EXCL : 해당 키값으로 세마포어가 있으면 씹어라
	if((semid = semget(semkey, 3,SEMPERM |IPC_CREAT)) == -1){
		if(errno == EEXIST){
			// 현재 있는 세마 포어를 가져오겠다.
			//printf("%d\n", semid);
			semid = semget(semkey, 1, 0);
		}
	}
	else{
			// SETVAL 하면 세마포어값을 설정 2로 하겠다.
			status = semctl(semid,0,SETVAL,2);
	}
	// 여기는 에러 나는 부분.
	if(semid == -1 || status == -1){
		printf("aaaaa");
		return -1;
	}

	return semid;
}

int p(int semid)
{
	// 세마포어르 원래 값으로 돌려라 0으로 돌아감.
	// 세마포어 값을 1증가시켜라.. 윗줄과 아랫줄 합치는게 세마포어 1증가.
	struct sembuf p_buf = {0,-1,SEM_UNDO};
	if(semop(semid,&p_buf,1)== -1){
		return -1;
	}
	return 0;
}


int v(int semid)
{
	// 이것은 뺄셈 할때 이렇게 쓴다. 0,1 들어간거.UNDO 프로세스가 종료가될때 초기화를 시킨다.
	struct sembuf p_buf = {0,1, SEM_UNDO};
	// 세마포어에 있는 CNT 값이 -1 을 하고 리턴은 잘되면 0이다.
	if(semop(semid, &p_buf,1) == -1)
		return -1;
	return 0;
}
