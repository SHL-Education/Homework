#include<iostream>
using namespace std;

class A
{
	int val;
	public:
		A(int i)
		{
			cout<< "A(int i) Call" << endl;
			val = i;
		}
		A(const A& a)
		{
			cout << "const A& a) Call " <<endl;
			val = a.val;
		}
		void ShowData(void)
		{
			cout << "val:" << val <<endl;
		}
};
A function(A& a)
{

	return a;
}

int main(void)
{
	A a(10);
	function(a).ShowData();
	return 0;
}
