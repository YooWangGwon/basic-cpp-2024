// file : test19_struct01
// date : 240223
// desc : CŸ�� ����ü


# include<stdio.h>

// CŸ���� ����ü : ��� ������ ������

// ����ü  ����(CŸ�� ����)

typedef struct human {		// human ����ü(�����ڰ� ���� ����� ���� �ڷ���)
	char name[20]; // �Ӽ�;�������: name, age, job
	int age;
	char job[20];
}Human; // ������ human ����ü�� Human���� ����ϰڴ�.

void showhuman(Human h)
{
	printf("name : %s age : %d job : %s\n", h.name, h.age, h.job);
}


int main()
{
	int a;
	human h1 = { "ȫ�浿",50,"����" }; //Human Ÿ���� ������ �����ϰ� �ʱ�ȭ�� ��Ų��.
	showhuman(h1);

	return 0;
}
