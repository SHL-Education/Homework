#if 0

2번에 위치하는 것이 좋다.
fork()는 같은 Task를 복사하게 된다.
그리고 다시 그 코드를 사용할 것이라면
CPU의 Instruction Cache, Data Cache를 재활용하는 것이 최고다.
결론적으로 Cache Affinity를 적극 활용하자는 것이다.

#endif
