// file : test81_FunctionVirtualOverride.cpp
// date : 240304
// desc : �����Լ�

#include <iostream>
using namespace std;

class First
{
public:
	virtual void MyFunc() { cout << "FirstFunc" << endl; }	// ���� �Լ� ����
};

class Second : public First
{
public:
	virtual void MyFunc() { cout << "SecondFucn" << endl; }	// ���� �Լ� ����
};

class Third : public Second
{
public:
	virtual void MyFunc() { cout << "ThirdFunc" << endl; }	// ���� �Լ� ����
};

int main(void)
{
	Third* tptr = new Third();	// ��ü Ÿ���� Third Ŭ���� Ÿ��	// ���� ���ε� : ���α׷��� ����� �� ȣ���ؾ��� ����Լ��� ����. �����Ͱ� ����Ű�� ��ü�� ���� ȣ��Ǵ� �Լ��� �޶����� ��.
	Second* sptr = tptr;		// 
	First* fptr = sptr;

	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();
	delete tptr;
	return 0;

}