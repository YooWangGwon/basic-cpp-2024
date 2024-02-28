// file : test53_ShallowCopyError.cpp
// date : 240228
// desc : ���� ������ ������

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Person
{private:
	char* name;
	int age;
public:
	Person(const char* myname, int myage)	// myname�� �̸����� ���ÿ� �޸� ������ �Ҵ��
	{
		cout << "������ ȣ��" << endl;
		int len = strlen(myname) + 1;
		name = new char[len];	// new �����ڸ� ���� heap ������ �޸� ������ �Ҵ����
		strcpy(name, myname);	// heap �������� �Ҵ���� name �̶�� �޸� ������ myname�� �ִ� Lee Dong Woo��� ���ڿ��� ����
		age = myage;
	}
	Person(const Person& copy)	 // ���� ���� ���¸� ���� ���� ������ ����
	{
		cout << "���� ���� ������ ȣ��" << endl;
		name = new char[strlen(copy.name) + 1];	//  new �����ڸ� ���� heap ������ �޸� ������ ���Ӱ� �Ҵ����
		strcpy(name, copy.name);	// ���� �Ҵ���� �޸� ������ man1�� name���� �����Ͽ� �������
		age = copy.age;		// ����� ��� ����
	}
	void ShowPersonInfo() const
	{
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}
	~Person()
	{
		delete[]name;	// heap������ �Ҵ���� name�̶�� �޸𸮸� ȸ��
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person man1("Lee dong woo", 29);
	Person man2 = man1;		// man2��� �̸����� �ʵ尡 ������ -> man1�� ���ڿ� �ּҰ��� �������� man�� �״�� ���Ե�
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;	// ��ü man1�� name �޸𸮸� ��ȯ�ϰ� �Ǹ�, ��ü man2�� ����� �޸� ����(���� name)�� ����Ű�� ������ �߻��ϰ� ��(���� ����) -> �Ҹ��ڰ� �ѹ��� �ߵ���
}				// -> ���� ���縦 ���ؼ��� ����Ʈ ���� �����ڰ� �ƴ� ������ ���� �����ڸ� ��������� �����ؾ���