#include<iostream>
using namespace std;

class Point 
{
	private:
		int x,y;
	public:
		Point(int _x=0, int _y= 0):x(_x),y(_y){}
		void ShowPosition(void);
		Point& operator ++(void);
		Point operator++(int);
}
;

void Point::ShowPosition(void)
{
	cout << x << " " << y << endl;
}

Point& Point::operator++(void)
{
	x++;
	y++;
	return *this;
}

Point Point::operator++(int)
{
	Point temp(x,y);
	//++(*this);
	x++;
	y++;
	return temp;
}

int main(void)
{
	Point p1(3,7);
	(p1++).ShowPosition();
	p1.ShowPosition();

	Point p2(33, 77);
	(++p2).ShowPosition();
	p2.ShowPosition();

	return 0;
}

