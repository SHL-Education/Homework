#ifndef __STUDENT_H__
#define __STUDENT_H__

class Student{
private:
	int math;
	int physics;
	int computer;

	int total;
	float ave;
	char credit;
public:
	void input_score(void);
	void calc_total(void);
	void average(void);
	void print_average(void);
};

#endif
