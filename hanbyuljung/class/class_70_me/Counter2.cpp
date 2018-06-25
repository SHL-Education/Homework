#include<iostream>
using namespace std;

class A
{
	private:
		int data;
		friend class B;
};

class B
{
	public:
		void SetData(A& a, int data)
		{
			a.data = data;
		}
};

int main(void)
{
	A a;
	B b;
	b.SetData(a,10);
	return 0;
}

