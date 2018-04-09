#if NO28
이것은 실제 가상 메모리 주소에 해당한다.
말 그대로 가짜 주소에 해당하지만
커널의 페이징 메커니즘에 의해 실제 물리 메모리로 변환된다.
#endif

/*
우리가 c 프로그래밍을 하면서 보는 주소는 모두 가상 메모리의 주소이며,
이 가상메모리 주소는 운영체제 커널의 페이징 메커니즘에 의해 실제 물리 메모리로 변경된다.
*/