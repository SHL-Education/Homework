#include<iostream>
#include<string.h>
using namespace std;

class Person
{
	int age;
	char name[20];
	public:
		int GetAge(void)const		// 함수 오버로딩을 할때 써먹는 const
		{
			return age;
		}
		const char *GetName(void) const
		{
			return name;
		}
		Person(int _age = 1, char *_name = "noname")
		{
			age = _age;
			strcpy(name, _name);
		}
};

class Student: public Person
{
	char major[20];
	public:
		Student(char *_major)
		{
			strcpy(major, _major);
		}
		const char *GetMajor(void) const
		{
			return major;
		}
		void ShowData(void) const
		{
			cout << "name: " << GetName() << endl;
			cout << "age:" << GetAge() << endl;
			cout << "major:" << GetMajor() << endl;
		}

}
;
int main(void)
{
	Student Park("Computer Science");
	Park.ShowData();
	return 0;
}

