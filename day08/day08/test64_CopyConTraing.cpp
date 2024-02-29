// file : test64_CopyConTraing.cpp
// date : 240229
// desc : ���� ���� ������ �ǽ�

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Person
{
private:
	char* name;
	int age;
public:
	Person(const char* pname, int page)
	{
		cout << "�Ϲ� ������ ȣ��" << endl;
		name = new char[strlen(pname) + 1];
		strcpy(name, pname);
		age = page;
	}
	Person(const Person& copy)
	{
		cout << "���� ������ ȣ��" << endl;
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
		age = copy.age;
	}

	void PersonInfo()
	{
		cout << "�Ż� ���� ���" << name << endl;
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}
	~Person()
	{
		cout << "�Ҹ��� ����" << endl;
		delete[]name;	// heap���� �޸� ���� ��ȯ
		cout << "�޸� ���� ��ȯ" << endl;
	}
};

int main(void)
{
	Person p("���ձ�", 25);
	p.PersonInfo();

	Person copyp(p);
	copyp.PersonInfo();

	return 0;
}