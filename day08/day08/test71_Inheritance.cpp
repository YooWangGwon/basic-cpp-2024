// file : test71_Inheritance.cpp
// date : 240229
// desc : ���(Inheritance)�� �������� ����

# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
using namespace std;

class Person
{
	char name[50];
	int age;
public:
	Person(const char* myname, int myage) 
	{
		cout << "�θ������, Person ������ ����" << endl;
		strcpy(name, myname);
		age = myage;
	}
	void WhatYourName() const 
	{
		cout << "My name is " << name << endl;
	}
	void HowOldAreYou() const
	{
		cout << "I'm " << age << " years old." << endl;
	}
};

class UnivStudent : public Person // Person Ŭ������  ����� �ǹ���, Person class �� �����ִ� UnivStudent -> Person class�� �ִ� �͵��� UnivStudent class�� ���Ѿ��� �����޴´� 
{
private:
	string major;	// UnivStudent class ���������� ������ �ִ� �������(field), string :  C++ STL���� �����ϴ� Ŭ������, string(���ڿ�)�� �ٷ�� Ŭ����
public:
	UnivStudent(const char* myname, int myage, const string mymajor) : Person(myname, myage)	// �θ� Ŭ������ ���� ��������� private�̱� ������ �θ� �����ڸ� ���ؼ� �ʱ�ȭ�� �̷������ 
	{																							// �ڽ� Ŭ������ �ִ� ��������� �ڽ� Ŭ������ �����ڿ��� �ʱ�ȭ
		cout << "�ڽĻ�����, UnivStudent ������ ����" << endl;									// �θ� �����ڰ� ���� ����ǰ� �� ������ �ڽ� �����ڰ� �����
		major = mymajor;																		// ���� �θ� Ŭ������ ��������� private�� �ƴ� protected�� public�̸� �ڽ� Ŭ������ �����ڿ��� �ʱ�ȭ ����
	}
	void WhoAreYou() const
	{
		WhatYourName();	// UnivStudent Ŭ�������� WhatYourName �Լ��� HowOldAreYou �Լ��� ���ǵǾ� ���� �������� 
		HowOldAreYou();	// �� �Լ��� ����Լ��� ������Person Ŭ������ ����߱� ������ �� �Լ��� ȣ���� �� �ִ�.
		cout << "My major is " << major << endl << endl;
	}
};
int main(void)
{
	Person p1("��ö��", 24);
	p1.WhatYourName();
	p1.HowOldAreYou();
	cout << endl;
	UnivStudent p2("���ձ�", 25, "��������к�");	// �ڽĻ����� ȣ�� -> �θ������ ȣ�� -> �θ������ ���� -> �ڽĻ����� ����
	p2.WhoAreYou();
	return 0;
}