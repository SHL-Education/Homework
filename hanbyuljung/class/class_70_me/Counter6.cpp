#include<iostream>
using namespace std;

class A
{
	int val;
	public:
		A(int i)
		{
			cout << "A(int i)Call" << endl;
			val = i;
		}
		A(const A& a)
		{
			cout << "A(const A& a) Call" << endl;
			val = a.val;
		}
		void ShowData(void)
		{
			cout << "val:" << val << endl;
		}
}
;
void function(A a)
{
	a.ShowData();
}

int main(void)
{
	A obj(30);
	function(obj);
	return 0;
}

