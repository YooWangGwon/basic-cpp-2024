// file : test45_ObjArr2.cpp
// date : 240227
// desc : ��ü �迭2

# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
using namespace  std;

class Human {
private:
	char name[30];
	int age;

public:
	Human(const char * myname, int age)
	{
		cout << "������ ȣ��" << endl;
		strcpy(name, myname);
		this->age = age;
	}
	void HumanInfo()
	{
		cout << "�̸�: " << name << " ";
		cout << "����: " << age << endl<<endl;
	}
	~Human()
	{
		cout << "�Ҹ��� ȣ��!" << endl;
	}
};

int main(void)
{
	Human h[3] = { Human("ȫ�浿",50), Human("��ö��",40), Human("�迵��",30) }; //��ü�迭

	for (int i = 0; i < 3; i++)
		h[i].HumanInfo(); // i��° �濡 �ִ� ��ü�� ������ ���

	Human* h1 = new  Human("������", 50); // Human Ÿ���� ��ü�� heap�������� �����ϰ� �� �ּҰ��� Human Ÿ���� h1 ������ ������ ����
	h1->HumanInfo();					  // �ַο� �����ڸ� ���� ������ ���� h1�� ����Ű�� HumanŸ���� ��ü�� �����Ͽ� HumanInfo�Լ��� ���

	Human h2("�󸶹�", 30); // HumanŸ���� ��ü h2 ����
	h2.HumanInfo(); // ��ü h2�� �����Ͽ� HumanInfo�Լ��� ���

	return 0;
}