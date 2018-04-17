#if 0

외부 인터럽트의 경우 32 ~ 255까지의 번호를 사용한다.
여기서 128(0x80)에 해당하는 System Call만은 제외한다.
idt_table에서 128을 제외한 32 ~ 255 사이의 번호가 들어오면 실제 HW Device다.
여기서 같은 종류의 HW Device가 들어올 수 있는데
그들에 대해서 Interrupt를 공유하게 하기 위해
irq_desc라는 Table을 추가로 두고 active라는 것으로 Interrupt를 공유하게끔한다.

#endif
