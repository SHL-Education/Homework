#if 0

CPU마다 RQ, WQ가 1개씩 존재한다.
active 배열과 expired 배열이 존재해서
어떤 우선순위의 Process가 현재 올라가 있는지 bitmap을 체크하게되며
queue에는 만들어진 task_struct가 들어가 있게 된다.
즉, bitmap을 보고 우선순위에 해당하는 것이 존재하면
빠르게 queue[번호]로 접근해서 해당 task_struct를 RQ에 넣거나
주어진 Time Slice가 다했는데 수행할 작업이 남아 있다면
RQ에서 WQ로 집어넣는등의 작업을 수행한다.
결국 Scheduling이란 작업이 Multi-Tasking을 지원하는데 있어 핵심인 기술이다.
여러 Task들을 동시다발적으로 동작하는것처럼 보이게하는 트릭이라 할 수 있겠다.

#endif
