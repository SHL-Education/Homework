#if 0

include/linux/sched.h 에 있는 공용체로
내부에는 커널 스택 정보와 thread_info 를 가지고 있다.
이 안에는 현재 구동중인 task 의 정보가 들어 있고
Context Switching 등에 활용하기 위해 cpu_context_save 구조체가 존재한다.

#endif
