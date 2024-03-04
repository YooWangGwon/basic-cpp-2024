// file : file84_Virtual.cpp
// date : 240304
// desc : �����Լ�

# include <iostream>
using namespace std;

class Base
{
public:
	Base() {}
	~Base() {}
	virtual void func1() { cout << "Base::func1()" << endl; }
	virtual void func2() { cout << "Base::func2()" << endl; }
	void func3() { cout << "Base::func3()" << endl; }
};

class Derived : public Base
{
public:
	Derived() {}
	~Derived() {}
	void func1() { cout << "Derived::func1()" << endl; }
	void func3() { cout << "Derived::func2()" << endl; }
	void func4() { cout << "Derived::func3()" << endl; }
};

int main()
{
	Base b;						// Base Ÿ���� ��ü����
	Derived d;					// Derived Ÿ���� ��ü ���� 
	Base* pb = new Derived();	// Base Ÿ���� ��ü ������

	pb->func1();
	pb->func2();
	pb->func3();	// Base Ŭ������ func3() ȣ��

	Derived* pd = &d;
	pd->func1();
	pd->func2();
	pd->func3();
	pd->func4();

	delete pb;

	return 0;
}