// file : test18_struct02.cpp
// date : 240223
// desc : C++Ÿ�� ����ü

// C++ Ÿ���� ����ü : ����ü ����� ��� ������ ��� �Լ��� ������.

# include<iostream>

typedef struct human {
	char name[20];
	int age;
	char job[20];

	void showhuman() // ����Լ� : ����� ���. ����ü �ȿ� �ִ� �Լ��̱� ������ ���� �Է��� ���� �ʿ䰡 ����.
	{
		printf("name : %s, age : %d, job : %s\n", name, age, job); // ����ü �ȿ� �ִ� �Լ��̱� ������ h.name�� �ƴ� name���� ����
	}
}Human; // ������ human ����ü�� Human���� ����ϰڴ�.

int main()
{
	int a;
	human h1 = { "ȫ�浿",50,"����" }; //Human Ÿ���� ������ �����ϰ� �ʱ�ȭ�� ��Ų��.
	h1.showhuman();

	return 0;
}
