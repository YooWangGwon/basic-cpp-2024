// file : test65_NeedGlobal.cpp
// date : 240229
// desc : ���������� �ʿ��� ��Ȳ

#include <iostream>
using namespace std;
		
int simObjCnt = 0;		// �������� ����1
int cmxObjCnt = 0;		// �������� ����2

class SoSimple
{
public:
	SoSimple()
	{
		simObjCnt++;	// ��ü�� ������ �� ���� simObjCnt�� 1�� ����
		cout << simObjCnt << "��° SoSimple ��ü" << endl;
	}
};

class SoComplex
{
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "��° SoComplex ��ü" << endl;
	}
	SoComplex(SoComplex& copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "��° SoComplex ��ü" << endl;
	}
};

int main(void)
{
	SoSimple sim1;
	SoSimple sim2;

	SoComplex com1;
	SoComplex com2 = com1;	// ��������ڿ� ���� ��ü ����
	SoComplex();			// �ӽð�ü ����
	return 0;
}