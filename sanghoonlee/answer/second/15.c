#if 0

우리가 사용하는 프로그램에서는 반드시 순차적으로 동작해야 하는 구간이 존재하고
또한 쓸대없이 순차적으로 동작하면 성능에 손해를 보는 구간도 존재한다.

이러한 것 때문에 User Level에서 thread를 사용할 경우
Critical Section이 존재한다면 Lock Mechanism을 사용한다.

Lock Mechanism을 사용중일 경우에는
Interrupt 를 맞으면 안되기 때문에 TASK_UNINTERRUPTIBLE이 필요하다.

반대로 그렇지 않은 경우라면
Interrupt에 무관하므로 TASK_INTERRUPTIBLE을 사용한다.

#endif
