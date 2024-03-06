// file : test101_InheritAssignOperation.cpp
// date : 240306
// desc : 상속 구조에서의 대입 연산자 호출

#include <iostream>
using namespace std;

class First
{
private:
	int num1, num2;
public:
	First(int n1 = 0, int n2 = 0): num1(n1), num2(n2)
	{ }
	void ShowData() { cout << num1 << "," << num2 << endl; }

	First& operator=(const First& ref)
	{
		cout << "First& operator=()" << endl;
		num1 = ref.num1;
		num2 = ref.num2;
		return *this;
	}
};

class Second : public First
{
private:
	int num3, num4;
public:
	Second(int n1, int n2, int n3, int n4)
		:First(n1, n2), num3(n3), num4(n4)
	{ }
	void ShowData()
	{
		First::ShowData();
		cout << num3 << "," << num4 << endl;
	}
	
	Second& operator=(const Second& ref)	// 자식클래스에서 명시적으로 대입 연산자 오버로딩을 할 경우, 부모 클래스에 오버로딩된 대입연산자는 자동으로 호출되지 않는다. 
	{
		cout << "Second& operator=()" << endl;
		First::operator=(ref);	// 부모 클래스의 대입 연산자를 사용하려면 직접 호출해야만 한다.
								// -> 부모클래스에서 대입 연산자를 오버로딩 하지 않을 경우, 이 문장을 입력하면 부모 클래스의 디폴트 대입 연산자가 호출된다
		num3 = ref.num3;
		num4 = ref.num4;
		return *this;
	}
	
};

int main(void)
{
	Second ssrc(111, 222, 333, 444);
	Second scpy(0, 0, 0, 0);
	scpy = ssrc;
	scpy.ShowData();
	return 0;
}