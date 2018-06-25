#include<iostream>
#include<string.h>
using namespace std;

class Person
{
	char *name;
	char *phone;

	public:
		Person(char* _name, char *_phone);
		Person(const Person& p);
		~Person();
		void ShowData();
}
;
Person::Person(char *_name, char *_phone)
{
	name = new char[strlen(_name) +1];
	strcpy(name, _name);
	phone = new char[strlen(_phone) + 1];
	strcpy(phone, _phone);
}

Person::~Person(void)
{
	delete []name;
	delete []phone;
}

Person::Person(const Person& p)
{
	name = new char[strlen(p.name) +1];
	strcpy(name, p.name);
	phone = new char[strlen(p.phone) +1];
	strcpy(phone, p.phone);
}

void Person::ShowData(void)
{
	cout <<"name:" << name <<endl;
	cout << "phone:" << phone << endl;
}

int main (void)
{
	Person p1("Jo", "011-9272-6523");
	Person p2 =p1;

	return 0;
}


	

