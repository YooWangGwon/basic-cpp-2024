// file : test78_ObjectPointer
// date : 240304
// desc : ��ü ������ ����

# include<iostream>
using namespace std;

class Person	// 1���� ��� �Լ� ����
{
public:
	void Sleep() { cout << "Sleep" << endl; }
};

class Student : public Person	// 2���� ��� �Լ� ����
{
public:
	void Study() { cout << "Study" << endl; }
	void Sleep() { cout << "Sleep" << endl; } // �������̵�(OverRiding) : ���� Ŭ������ �Լ��� ���� Ŭ�������� ������
};

class PartTimeStudent : public Student	// 3���� ��� �Լ� ����
{
public: 
	void Work() { cout << "Work" << endl; }
};

int main(void)
{
	Student* ptr0 = new Student();			// �⺻������ ������ Ÿ������ ����ϴ� ���� ��Ģ�̴�
	Person* ptr1 = new Student();			// Person�� ������ ����(�θ� Ŭ����)�� Student ��ü(�ڽ� Ŭ����)�� ����Ŵ
	Person* ptr2 = new PartTimeStudent();	// Person�� ������ ������ PartTimeStudent ��ü�� ����Ŵ
	Student* ptr3 = new PartTimeStudent();	// Student�� ������ ������ PartTimeStudent ��ü�� ����Ŵ
	ptr1->Sleep();	// ��ü Ÿ����  Student�� Sleep()�Լ��� �ƴ� ��ü ������ Ÿ���� Person�� Sleep() �Լ� ��� -> ������ ��ü �������� Ÿ���� ����
	ptr2->Sleep();
	ptr3->Study();
	delete ptr1; delete ptr2; delete ptr3;
	return 0;
}

/*
- �θ� Ÿ���� ��ü �����ͷ� �ڽ� ��ü�� ����ų �� ����
- �ڽ� Ÿ���� ��ü �����ͷ� �θ� Ÿ�� ��ü�� ����ų �� ����
- ������ ��ü �������� Ÿ���� ����
*/