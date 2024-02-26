// file : test37:student.cpp
// date : 240226
// desc : Student Class �����

#include <iostream>
using namespace std;

class Student
{
private:
	const int ID;	// ����� �̸� �ʱ�ȭ�� �ؾ��ϱ� ������ ��ü�� �����Ǳ� ���� �ʱ�ȭ�� �Ǿ���Ѵ�.
	char name[30];	// ���ڿ� �迭�� �����ϰ� �ٷ� �ʱ�ȭ���� �ʴ� ���� strcpy()�� ���Ͽ� �ʱ�ȭ
	char major[30];
	int age;

public:
	// ���ڿ��� ����Ϸ��� ���ڿ��� ����Ǿ� �ִ� �ּҸ� ������ �� - ���ڿ��� ù���� ���� �ּҰ� �����
	Student( int sID, const char* sname, const char* smajor, int sage) : ID(sID) // -> ��� �̴ϼȶ����� : ��ü�� �����Ǳ� ���� �ʱ�ȭ(C++���� ����)
	  // ��� �̴ϼȶ������� ��ü ������ �ʱ�ȭ���� �ʴ� ������� �ʱ�ȭ �� �� ���. �� ��ü ������ ������� �̸� �ʱ�ȭ�� �Ǵ� ������� �ʱ�ȭ
	{ // ���ڿ��� �ּұ� ������ ������ ������ �־ ����Ѵ�. ������ �Ѽյ��� �ʱ� ���� ���ȭ
		//ID = sID;
		strcpy(name, sname);	// ���ڿ� �迭�� �����ϰ� �ٷ� �ʱ�ȭ���� �ʴ� ���� strcpy()�� ���Ͽ� �ʱ�ȭ �Ѵ�.
		strcpy(major, smajor);
		age = sage;
	}
	void StudentInfo()
	{
		cout << "�л� ���� ����" << endl;
		cout << "�й�: " << ID << endl;
		cout << "�̸�: " << name << endl;
		cout << "����: " << major << endl;
		cout << "����: " << age << endl<<endl;
	}
};

int main()
{
	Student s1(201811149, "���ձ�", "��������к�", 25); // ��ü�� �����ϸ� �����ڸ� ȣ���ؾ� �Ѵ�
	s1.StudentInfo();

	Student s2(202214237, "ȫ�浿", "��ǻ�Ͱ�������", 22);
	s2.StudentInfo();
	return 0;
}