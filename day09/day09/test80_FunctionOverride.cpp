// file : test80_FunctionOberride.cpp
// date : 240304
// desc : 객체포인터와 함수 오버라이드

#include <iostream>
using namespace std;

class First
{
public:
	void MyFunc() { cout << "FirstFunc" << endl; }
};

class Second : public First
{
public:
	void MyFunc() { cout << "SecondFunc" << endl; }
};

class Third : public Second
{
public:
	void MyFunc() { cout << "ThirdFunc" << endl; }
};

int main(void)
{
	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;

	/*
	객체 포인터 타입을 기준으로 접근 범위가 결정됨.
	오버라이딩 된 경우는 부모것은 자식으로 가려짐.
	오버라이딩 된 부모타입의 멤버함수를 쓰기위해선 범위스코프를 사용하여 호출.
	*/

	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();

	tptr->Second::MyFunc(); // 범위 스코프를 통해 오버라이딩 된 부모타입의 멤버함수를 호출
	delete tptr;
	return 0;
}