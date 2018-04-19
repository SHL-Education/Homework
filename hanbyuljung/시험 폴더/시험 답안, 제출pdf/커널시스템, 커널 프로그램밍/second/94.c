#if 0

우리가 만든 프로그램에서 fork() 가 호출되면
C Library 에 해당하는 glibc 의 __libc_fork() 가 호출됨
이 안에서 ax 레지스터에 시스템 콜 번호가 기록된다.
즉 sys_fork() 에 해당하는 시스템 콜 테이블의 번호가 들어가고
이후에 int 0x80 을 통해서 128 번 시스템 콜을 후출하게 된다.
그러면 제어권이 커널로 넘어가서 idt_table(Interrupt Descriptor Table)로 가고
여기서 시스템 콜은 128 번으로 sys_call_table 로 가서
ax 레지스터에 들어간 sys_call_table[번호] 의 위치에 있는
함수 포인터를 동작시키면 sys_fork() 가 구동이 된다.
sys_fork() 는 SYSCALL_DEFINE0(fork) 와 같이 구성되어 있다.

#endif
