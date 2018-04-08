#include "shm.h"

int CreateSHM(long key)
{
	//	0777의 권한을 준다.
	return shmget(key, sizeof(SHM_t), IPC_CREAT | 0777);
}

int OpenSHM(long key)
{
	return shmget(key, sizeof(SHM_t),0);
	// 나는 이포인터를 쉐어드 메모리로 지정할 것이다.
	// 그럼 공유된 페이지 주소를 얻는다. 물리주소에 있는...
}

SHM_t *GetPtrSHM(int shmid)
{
	// at는 공유메모리의 장소라고 생각하면 된다. 공유메로리 물리주소.
	// id 값을 가지고 찾는다. 맨 첫번째 주소부터 찾겠다.
	return (SHM_t *)shmat(shmid, (char *)0,0);
}
int FreePtrSHM(SHM_t *shmptr)
{
	return shmdt((char*)shmptr);
}
