#if 0

리눅스 커널의 Deadline Scheduler 는 Dario Faggioli 에 의해
2013 년 3 월 Linux Kernel v3.14 에서 소개되었다.

Deadline Scheduler 는 EDF + CBS 알고리즘 기반으로 동작한다.
임베디드 개발자들이 주로 원하는 기능이지만
우리의 펭귄 새끼 토발즈가 별로 탐탁치 않아 한다.
(CPU Scheduler 만으로 Real-Time 을 해결할 수 없다고 생각해서 그러함)

Task 마다 주어진 주기를 가지고 실행되는 것을 보장해야 한다.
dl Task 의 우선 순위는 종종 변동되는데,
만료 시각이 먼저 다가 오는 Task 에 우선 처리할 기회가 주어진다.

한 마디로 지금 당장 급한것부터 처리하자는 의미다.

#endif
