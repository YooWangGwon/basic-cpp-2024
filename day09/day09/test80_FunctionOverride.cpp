// file : test80_FunctionOberride.cpp
// date : 240304
// desc : ��ü�����Ϳ� �Լ� �������̵�

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
	��ü ������ Ÿ���� �������� ���� ������ ������.
	�������̵� �� ���� �θ���� �ڽ����� ������.
	�������̵� �� �θ�Ÿ���� ����Լ��� �������ؼ� ������������ ����Ͽ� ȣ��.
	*/

	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();

	tptr->Second::MyFunc(); // ���� �������� ���� �������̵� �� �θ�Ÿ���� ����Լ��� ȣ��
	delete tptr;
	return 0;
}