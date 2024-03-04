// file : test81_FunctionVirtualOverride.cpp
// date : 240304
// desc : 가상함수

#include <iostream>
using namespace std;

class First
{
public:
	virtual void MyFunc() { cout << "FirstFunc" << endl; }	// 가상 함수 선언
};

class Second : public First
{
public:
	virtual void MyFunc() { cout << "SecondFucn" << endl; }	// 가상 함수 선언
};

class Third : public Second
{
public:
	virtual void MyFunc() { cout << "ThirdFunc" << endl; }	// 가상 함수 선언
};

int main(void)
{
	Third* tptr = new Third();	// 객체 타입은 Third 클래스 타입	// 동적 바인딩 : 프로그램이 실행될 떄 호출해야할 멤버함수를 결정. 포인터가 가리키는 객체에 따라 호출되는 함수가 달라지는 것.
	Second* sptr = tptr;		// 
	First* fptr = sptr;

	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();
	delete tptr;
	return 0;

}