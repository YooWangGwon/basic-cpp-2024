// file : test37:student.cpp
// date : 240226
// desc : Student Class 만들기

#include <iostream>
using namespace std;

class Student
{
private:
	const int ID;	// 상수는 미리 초기화를 해야하기 때문에 객체가 생성되기 전에 초기화가 되어야한다.
	char name[30];	// 문자열 배열을 선언하고 바로 초기화하지 않는 경우는 strcpy()를 통하여 초기화
	char major[30];
	int age;

public:
	// 문자열을 사용하려면 문자열이 저장되어 있는 주소를 만들어야 함 - 문자열의 첫번쨰 문자 주소가 저장됨
	Student( int sID, const char* sname, const char* smajor, int sage) : ID(sID) // -> 멤버 이니셜라이저 : 객체가 생성되기 전에 초기화(C++에만 존재)
	  // 멤버 이니셜라이저는 객체 생성시 초기화되지 않는 멤버들을 초기화 할 때 사용. 즉 객체 생성과 상관없이 미리 초기화가 되는 멤버들의 초기화
	{ // 문자열은 주소기 때문에 포인터 변수에 넣어서 사용한다. 원본이 훼손되지 않기 위해 상수화
		//ID = sID;
		strcpy(name, sname);	// 문자열 배열을 선언하고 바로 초기화하지 않는 경우는 strcpy()를 통하여 초기화 한다.
		strcpy(major, smajor);
		age = sage;
	}
	void StudentInfo()
	{
		cout << "학생 정보 열람" << endl;
		cout << "학번: " << ID << endl;
		cout << "이름: " << name << endl;
		cout << "전공: " << major << endl;
		cout << "나이: " << age << endl<<endl;
	}
};

int main()
{
	Student s1(201811149, "유왕권", "국제통상학부", 25); // 객체를 생성하면 생성자를 호출해야 한다
	s1.StudentInfo();

	Student s2(202214237, "홍길동", "컴퓨터공학전공", 22);
	s2.StudentInfo();
	return 0;
}