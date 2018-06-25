#include<iostream>
using namespace std;

calss Point {
	private:
		int x, y;
	public:
		Point(int _x = 0, int _y = 0) : x(_x), y(_y){}
		void ShowPosition(void);
		Point operator +(const Point&);

}
;
void Point ::ShowPosition(void)
{
	cout << x << " " << y << endl;
}

Point Point:: operator +(const Point& p)
{
	Point temp(x + p.x, y+p.y);
	return temp;
}
int main(void)
{
	Point p1(1,2);
	Point p2(3,7);
	Point p3 = p1 +p2;
	p3.ShowPoition();
	return 0;

}
