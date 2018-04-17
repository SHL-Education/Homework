#if 0

메모리 접근 속도가 같은 것을 Bank라 한다.
그리고 Kernel에서 이들은 Node라 한다.
UMA는 모든 CPU가 메모리 접근 속도가 같은 SMP와 같은것을 의미한다.
NUMA는 CPU 마다 메모리 접근 속도가 다른 Intel의 i계열의 CPU군을 의미한다.
Linux Kernel에선 이를 contig_page_data 를 통해 전역변수로 관리한다.
그리고 UMA의 경우엔 Node가 1개인데 pglist_data 구조체로 표현된다.
NUMA의 경우엔 pglist_data가 여러개 연결되어 있다.

#endif
