#if 0

Kernel Source 에서 아래 파일에 위치한다.

fs/open.c 에 위치하며 SYSCALL_DEFINE3(open, ~~~ ) 형태로 구동된다.

이 부분의 매크로를 분석하면 결국 sys_open() 이 됨을 알 수 있다.

#endif
