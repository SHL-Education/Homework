#include<iostream>
using namespace std;

class Point
{
	int x, y;
	public:
	Point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	void ShowData(void)
	{
		cout << x << ' ' << endl;
		cout << y << ' ' << endl;
	}
}
;

int main (void)
{
	Point p1 (10, 20);
	Point p2 (p1);

	p1.ShowData();
	p2.ShowData();
	return 0;
}

