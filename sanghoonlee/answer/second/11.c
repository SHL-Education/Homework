#if 0

먼저 vi -t current 로 검색하면
아래 헤더 파일에 x86 에 한하여 관련 정보를 확인할 수 있다.

arch/x86/include/asm/current.h

여기서 get_current() 매크로를 살펴보면 ARM 의 경우에는 아래 파일에

include/asm-generic/current.h

thread_info->task 를 확인할 수 있다.
x86 의 경우에는 동일한 파일 위치에서
this_cpu_read_stable() 함수에 의해 동작한다.

이 부분을 살펴보면 아래 파일

arch/x86/include/asm/percpu.h 에서

percpu_stable_op("mov", var) 매크로를 통해 관리됨을 볼 수 있다.
Intel 방식의 특유의 세그먼트 레지스터를 사용하여
관리하는 것을 볼 수 있는 부분이다.

#endif
