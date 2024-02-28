#include<iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{ }
	SoSimple& Addnum(int n)
	{
		num += n;
		return *this;
	}
	void SimpleFunc()
	{
		cout << "SimpleFunc: " << num << endl;
	}
	void SimpleFunc() const
	{
		cout << "const SimpleFunc: " << num << endl;
	}
};

void YourFunc(const SoSimple& obj)	// 전달되는 인자를 const 참조자로 받음.
{
	obj.SimpleFunc();	// const참조자로 받기 때문에 const 멤버함수가 호출됨
}


int main(void)
{
	SoSimple obj1(2);		// 일반 객체 생성
	const SoSimple obj2(7);	// const 객체 생성

	obj1.SimpleFunc();	// 일반객체의 일반 멤버함수 호출
	obj2.SimpleFunc();	// const객체의 const 멤버함수 호출

	YourFunc(obj1);	
	YourFunc(obj2);
	return 0;
}