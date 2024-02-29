// file : test74_DestModel.cpp
// date : 240229
// desc : 유도 클래스의 생성자 및 소멸자 정의의 모델(p.293~294)


# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <cstring>
using namespace std;

class Person
{
private:
	char* name;
public:
	Person(const char* myname)
	{
		cout << "부모 생성자 실행" << endl;
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
	}
	~Person()
	{
		cout << "부모 소멸자 실행" << endl;
		delete[]name;
	}
	void WhatYourName() const
	{
		cout << "My name is " << name << endl;
	}
};

class UnivStudent : public Person
{
private:
	char* major;
public:
	UnivStudent(const char* myname, const char* mymajor) : Person(myname)
	{
		cout << "자식 생성자 실행" << endl;
		major = new char[strlen(mymajor) + 1];
		strcpy(major, mymajor);
	}
	~UnivStudent()
	{
		cout << "자식 소멸자 실행" << endl;
		delete[]major;
	}
	void WhoAreYou() const
	{
		WhatYourName();
		cout << "My major is " << major << endl << endl;
	}
};

int main(void)
{
	UnivStudent st1("Kim", "Mathematics");
	st1.WhoAreYou();
	UnivStudent st2("Hong", "Physics");
	st2.WhoAreYou();
	return 0;
}