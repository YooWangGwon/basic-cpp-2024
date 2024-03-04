// file : test85_VirtualDestructor.cpp
// date : 240304
// desc : 가상소멸자(p.357~360)

#include <iostream>
using namespace std;

class First
{
private:
	char* strOne;
public:
	First(const char* str)
	{
		strOne = new char[strlen(str) + 1];
	}
	virtual ~First()	// 가상소멸자
	{
		cout << "~First()" << endl;
		delete[]strOne;
	}
};

class Second : public First
{
private:
	char* strTwo;
public:
	Second(const char* str1, const char* str2) : First(str1)
	{
		strTwo = new char[strlen(str2) + 1];
	}
	~Second()
	{
		cout << "~Second()" << endl;
		delete[] strTwo;
	}
};

int main(void)
{
	/*
	상속 관계에 있어서 객체 포인터는 조심해야한다.
	부모타입의 객체 포인터로 자식 객체를 가리키는 경우(다형성)에 조심해야한다.
	*/
	First* ptr = new Second("simple", "complex");
	delete ptr;	// 가상소멸자를 하지 않을 경우, 부모클래스의 소멸자만 호출됨 -> 객체 포인터 타입이 중시되기 때문 -> str2가 할당받음 메모리 영역이 반납되지 않음
	return 0;	// 가상소멸자를 적용 한 경우, 자식 클래스의 소멸자가 먼저 호출되고 부모 클래스의 소멸자가 호출됨
}				