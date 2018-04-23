#if 0

Device Driver 에서 class_create, device_create 를 이용해서
Character Device 인 /dev/장치파일을 만든다.
그리고 Character Device Driver를 등록하기 위해서는
register_chrdev()가 동작해야 한다.

동적으로 할당할 경우에는 alloc_chrdev_region() 이 동작한다.
이때 file_operations를 Wrapping할 구조체를 전달하고
Major Number와 장치명을 전달한다.

chrdevs 배열에 Major Number에 해당하는 Index에
file_operations를 Wrapping한 구조체를 저장해둔다.

그리고 이후에 실제 User 쪽에서 생성된 장치가 open 되면
그때는 Major Number에 해당하는 장치의 File Descriptor가 생성되었으므로
이 fd_array 즉, file 구조체에서 i_mode를 보면
Character Device임을 알 수 있고
i_rdev를 보고 Major Number와 Minor Number를 파악할 수 있다.

그리고 chrdevs에 등록한 Major Number와 같음을 확인하고
이 fd_array에 한해서는 open, read, write, lseek, close등의
file_operations 구조체 내에 있는 함수 포인터들을
앞서 Wrapping한 구조체로 대체한다.

그러면 User에서 read()등을 호출할 경우 우리가 알고 있는 read가 아닌
Device Driver 작성시 새로 만든 우리가 Wrapping한 함수가 동작하게 된다.

#endif
