#if 0

task_struct
mm_struct
vm_area_struct
signal_struct
sigpending
sighand_struct
rt_rq
dl_rq
cfs_rq
files_struct
file
file_operations
path
dentry
inode
super_block
sys_call_table
idt_table
do_IRQ()
Buddy, Slab 할당자
SYSCALL_DEFINE0(fork) 등등이 다루어지면 됨

먼저 마우스를 움직여서 더블 클릭한다는 것은 HW 신호에 해당하므로
인터럽트가 발생해서 마우스 인터럽트를 처리하게 된다.
처리된 인터럽트가 게임을 실행하는 것이라면
fork() 를 수행하고 자식 프로세스를 execve() 하여
게임에 해당하는 메모리 레이아웃으로 변형한다.
이때 사용되는 것이 sys_fork() 와 sys_execve() 로
sys_fork() 를 통해 새로운 task_struct 를 생성하고
sys_execve() 를 통해 ELF Header 와 Program Headers 에서
읽은 내용들을 기반으로 가상 메모리 레이아웃을 만들게 된다.

물론 이 때 먼저 게임이라는 실행 파일을 디스크에서 찾아야 하므로
super_block 을 통해서 파일 시스템의
메타 정보와 '/' 파일 시스템의 위치를 찾아온다.
이를 기반으로 파일이 실제 디스크 블록 어디에 있는지 찾고
그 다음에 앞서 기술했던 내용들을 진행한다.

그러면서 물리 메모리도 할당 해야 하는데
Demand On Paging 에 의해서 Page Fault 가 발생하고
이를 처리하기 위해 Page Fault Handler 도 동작할 것이다.

게임에 접속하기 위해 Networking 도 발생할 것이고
다른 프로세스들과 Context Switching 도 빈번하게 발생하면서
Run Queue 와 Wait Queue 를 왔다 갔다 할 것이다.

#endif
