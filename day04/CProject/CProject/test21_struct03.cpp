// file : test21_struct03.cpp
// date : 240223
// desc : C++ Ŭ����

# include<iostream>


class human {
public: // ���� ���� 
	char name[20];
	int age;
	char job[20];

	void showhuman() // ����Լ� : ����� ���. ����ü �ȿ� �ִ� �Լ��̱� ������ ���� �Է��� ���� �ʿ䰡 ����.
	{
		printf("name : %s, age : %d, job : %s\n", name, age, job);
	}
}Human; // ������ human ����ü�� Human���� ����ϰڴ�.

int main()
{
	int a = 10;
//	human h1 = { "ȫ�浿",50,"����" }; //Human Ÿ���� ������ �����ϰ� �ʱ�ȭ�� ��Ų��.
//	h1.showhuman();

	human h1 = { "ȫ�浿", 50, "����" };
	h1.showhuman();

	return 0;
}
