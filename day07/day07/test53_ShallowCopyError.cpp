// file : test53_ShallowCopyError.cpp
// date : 240228
// desc : 얕은 복사의 문제점

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Person
{private:
	char* name;
	int age;
public:
	Person(const char* myname, int myage)	// myname의 이름으로 스택에 메모리 공간이 할당됨
	{
		cout << "생성자 호출" << endl;
		int len = strlen(myname) + 1;
		name = new char[len];	// new 연산자를 통해 heap 영역에 메모리 공간을 할당받음
		strcpy(name, myname);	// heap 영역에서 할당받은 name 이라는 메모리 공간에 myname에 있는 Lee Dong Woo라는 문자열을 저장
		age = myage;
	}
	Person(const Person& copy)	 // 깊은 복사 형태를 위한 복사 생성자 선언
	{
		cout << "깊은 복사 생성자 호출" << endl;
		name = new char[strlen(copy.name) + 1];	//  new 연산자를 통해 heap 영역에 메모리 공간을 새롭게 할당받음
		strcpy(name, copy.name);	// 새로 할당받은 메모리 공간에 man1의 name값을 복사하여 집어넣음
		age = copy.age;		// 멤버대 멤버 복사
	}
	void ShowPersonInfo() const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~Person()
	{
		delete[]name;	// heap영역에 할당받은 name이라는 메모리를 회수
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person man1("Lee dong woo", 29);
	Person man2 = man1;		// man2라는 이름으로 필드가 생성됨 -> man1의 문자열 주소값과 정수값이 man에 그대로 대입됨
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;	// 객체 man1의 name 메모리를 반환하게 되면, 객체 man2는 사라진 메모리 공간(기존 name)을 가리키는 에러가 발생하게 됨(얕은 복사) -> 소멸자가 한번만 발동됨
}				// -> 깊은 복사를 위해서는 디폴트 복사 생성자가 아닌 별도의 복사 생성자를 명시적으로 구현해야함