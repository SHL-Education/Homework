#include<iostream>
using namespace std;

class Counter
{
	int val;
	public:
		Counter(void)
		{
			val=0;
		}
		void Print(void)
		{
			cout << val << endl;
		}
		friend void SetVal(Counter& C, int val);
};

void SetVal(Counter& c, int val)
{
	c.val = val;
}

int main(void)
{
	Counter cnt;
	cnt.Print();
	SetVal(cnt, 2002);
	cnt.Print();
	return 0;
}
