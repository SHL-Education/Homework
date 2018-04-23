#if 0

Page Fault 는 가상 메모리를 물리 메모리로 변환하는 도중
물리 메모리에 접근했더니 할당된 페이지가 없을 경우 발생한다.
이것이 발생하면 현재 수행중이던 ip(pc) 레지스터를 저장하고
페이지에 대한 쓰기 권한을 가지고 있다면
Page Fault Handler 를 구동시켜서 페이지를 할당하고
저장해놨던 ip(pc) 를 복원하여 다시 Page Fault 가 발생했던 루틴을 구동시킨다.
만약 쓰기 권한이 없다면 Segmentation Fault 를 발생시킨다.

#endif
