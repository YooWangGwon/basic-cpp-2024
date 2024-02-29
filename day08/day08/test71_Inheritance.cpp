// file : test71_Inheritance.cpp
// date : 240229
// desc : 상속(Inheritance)의 문법적인 이해

# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
using namespace std;

class Person
{
	char name[50];
	int age;
public:
	Person(const char* myname, int myage) 
	{
		cout << "부모생성자, Person 생성자 실행" << endl;
		strcpy(name, myname);
		age = myage;
	}
	void WhatYourName() const 
	{
		cout << "My name is " << name << endl;
	}
	void HowOldAreYou() const
	{
		cout << "I'm " << age << " years old." << endl;
	}
};

class UnivStudent : public Person // Person 클래스의  상속을 의미함, Person class 에 속해있는 UnivStudent -> Person class에 있는 것들을 UnivStudent class가 제한없이 물려받는다 
{
private:
	string major;	// UnivStudent class 실질적으로 가지고 있는 멤버변수(field), string :  C++ STL에서 제공하는 클래스로, string(문자열)을 다루는 클래스
public:
	UnivStudent(const char* myname, int myage, const string mymajor) : Person(myname, myage)	// 부모 클래스에 속한 멤버변수는 private이기 떄문에 부모 생성자를 통해서 초기화가 이루어지고 
	{																							// 자식 클래스에 있는 멤버변수는 자식 클래스의 생성자에서 초기화
		cout << "자식생성자, UnivStudent 생성자 실행" << endl;									// 부모 생성자가 먼저 실행되고 그 다음에 자식 생성자가 실행됨
		major = mymajor;																		// 만약 부모 클래스의 멤버변수가 private가 아닌 protected나 public이면 자식 클래스의 생성자에서 초기화 가능
	}
	void WhoAreYou() const
	{
		WhatYourName();	// UnivStudent 클래스에는 WhatYourName 함수와 HowOldAreYou 함수가 정의되어 있지 않음에도 
		HowOldAreYou();	// 두 함수를 멤버함수로 가지는Person 클래스를 상속했기 떄문에 두 함수를 호출할 수 있다.
		cout << "My major is " << major << endl << endl;
	}
};
int main(void)
{
	Person p1("김철수", 24);
	p1.WhatYourName();
	p1.HowOldAreYou();
	cout << endl;
	UnivStudent p2("유왕권", 25, "국제통상학부");	// 자식생성자 호출 -> 부모생성자 호출 -> 부모생성자 실행 -> 자식생성자 실행
	p2.WhoAreYou();
	return 0;
}