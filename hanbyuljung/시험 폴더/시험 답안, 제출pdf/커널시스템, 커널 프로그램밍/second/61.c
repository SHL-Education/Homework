#if 0

Hyper Threading 은 Pentium 4 에서
최초로 구현된 SMT(Simultaneous Multi-Threading) 기술명이다.
Kernel 내에서 살펴봤던 Context를 HW 차원에서 지원하기 때문에
실제 1개 있는 CPU가 논리적으로 2개가 있는것처럼 보이게 된다.
HW상에서 회로로 이를 구현하는 것인데
Kernel에서 Context Switching에선 Register들을 저장했다면
이것을 HW 에서는 이러한 HW Context 들을 복사하여
Context Switching 의 비용을 최소화하는데 목적을 두고 있다.
TLP(Thread Level Parallelization) 입장에서보면
Mutex 등의 Lock Mechanism 이 사용되지 않는한
여러 Thread 는 완벽하게 독립적이므로 병렬 실행될 수 있다.
한마디로 Hyper Threading 은 Multi-Core 에서 TLP 를 극대화하기에 좋은 기술이다.

#endif
