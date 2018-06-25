#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;
// type 을 알아서 정해주는 녀석 이다. template
template <typename T>
T Add(T a, T b)
{
	return a + b;
}

int main(void)
{
	cout << Add(10, atoi("12")) << endl;
	cout << Add(1.1, 2.2) << endl;
	return 0;
}

