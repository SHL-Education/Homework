#include<iostream>
using namespace std;

class A
{
	public:
		A(void)	// 첫번째꺼를 받음.
		{
			cout << "A()Call"<< endl;
		}
		A(int i)	// 두번째꺼를 받음.
		{
			cout << "A(int i)) Call" << endl;
		}
		A(const A& a)	// 복사 생성자
		{
			cout <<"A(const A& a) Call" <<endl;
		}
}
;

int main (void)
{
	 A obj1;
	 A obj2(10);
	 A obj3(obj2);
	 return 0;
}

