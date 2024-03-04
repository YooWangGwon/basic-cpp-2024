// file : test86_ReferenceAttribute.cpp
// date : 240304
// desc : �������� �������ɼ�(p.360~362)

# include<iostream>
using namespace std;

class First
{
public:
	void FirstFunc() { cout << "FirstFunc()" << endl; }
	virtual void SimpleFunc() { cout << "First's SimpleFunc()" << endl; }
};

class Second : public First
{
public:
	void SecondFunc() { cout << "SecondFunc()" << endl; }
	virtual void SimpleFunc() { cout << "Second's SimpleFunc()" << endl; }
}; 

class Third : public Second
{
public:
	void ThirdFunc() { cout << "ThirdFunc()" << endl; }
	virtual void SimpleFunc() { cout << "Third's SimpleFunc()" << endl; }
};

int main(void)
{
	Third obj;			// // Third Ŭ���� Ÿ�� ��ü obj ����
	obj.FirstFunc();
	obj.SecondFunc();
	obj.ThirdFunc();
	obj.SimpleFunc();
	
	cout << endl;
	Second& sref = obj;	// Third Ŭ���� Ÿ�� ��ü obj�� Second Ŭ���� Ÿ�� �����ڷ� ����
	sref.FirstFunc();
	sref.SecondFunc();
	sref.SimpleFunc();	// SimpleFunc�� �����Լ��� Third Ŭ������ SimpleFunc�Լ��� ȣ���

	cout << endl;
	First& fref = obj; 	// Third Ŭ���� Ÿ�� ��ü obj�� First Ŭ���� Ÿ�� �����ڷ� ����
	fref.FirstFunc();
	fref.SimpleFunc();	// // SimpleFunc�� �����Լ��� Third Ŭ������ SimpleFunc�Լ��� ȣ���
	return 0;
}