// file : test64_CopyConTraing.cpp
// date : 240229
// desc : 깊은 복사 생성자 실습

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Person
{
private:
	char* name;
	int age;
public:
	Person(const char* pname, int page)
	{
		cout << "일반 생성자 호출" << endl;
		name = new char[strlen(pname) + 1];
		strcpy(name, pname);
		age = page;
	}
	Person(const Person& copy)
	{
		cout << "복사 생성자 호출" << endl;
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
		age = copy.age;
	}

	void PersonInfo()
	{
		cout << "신상 정보 출력" << name << endl;
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~Person()
	{
		cout << "소멸자 실행" << endl;
		delete[]name;	// heap영역 메모리 공간 반환
		cout << "메모리 공간 반환" << endl;
	}
};

int main(void)
{
	Person p("유왕권", 25);
	p.PersonInfo();

	Person copyp(p);
	copyp.PersonInfo();

	return 0;
}