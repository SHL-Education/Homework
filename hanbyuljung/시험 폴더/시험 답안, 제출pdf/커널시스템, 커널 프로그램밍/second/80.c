#if 0

리눅스 커널에 존재하는 Task를 나타내는 구조체인
task_struct내에 files_struct내에 file 구조체에 대한 포인터가 fd_array다.
거기서 우리가 System Programming에서 얻는 fd는 바로 이 fd_array에 대한 index다.

#endif
