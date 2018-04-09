#include<stdio.h>
#include<pthread.h>


// 리턴도 모든지 하고 인자도 모든지 받을 수 있다.
// void 를 쓰는 이유. 
void *task1(void *X)
{
	printf("Thread A Complete\n");
}

void *task2(void *X)
{
	printf("Thread B Complete\n");

}

int main(void)
{
	pthread_t ThreadA, ThreadB;

	// a 와 b 에 뭔가를 넣어주려하고 있음. task1,task2를 구동시키겠다.
	// 쓰레드를 이렇게 동작 시키겠다고 등록 시킨것이다.
	// 앞뒤로 아무것도 안붙였다는 뜻이다. null은.
	pthread_create(&ThreadA, NULL, task1, NULL);
	pthread_create(&ThreadB, NULL, task2, NULL);

	// 조인을 하는 순간 메모리에 올리는 것이다.
	pthread_join(ThreadA, NULL);
	pthread_join(ThreadB, NULL);

		return 0;
}

// compile 시 -lpthread를 뒤에 붙여야 컴파일이 작동한다.

// thread는 종속적이다.
// 문제가 되는 곳은 critical section 이다.
// 그래서 lock을 걸어준다.

// 그래픽 카드는 속도는 느리다 하지만 밴드위스가 높다.
// 그래픽카드는cpu가 1000개정도 들어있다.
// 그래픽 카드는 밴드위스랑 갯수가 중요함
// 그래픽 카드는 병렬 처리, dsp는 빠른 처리를 할때 특화되어 있다.
// cpu는 순차 처리에 특화 되어있다.
