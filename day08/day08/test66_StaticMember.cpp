// file : test66_StaticMember.cpp
// date : 240229
// desc : static �������(Ŭ���� ����)

#include <iostream>
using namespace std;

class SoSimple
{
private:
	static int simObjCnt;	// private�̱� ������ �ܺο����� ������ ����
public:
	SoSimple()
	{
		simObjCnt++;										// �������ó�� ����Լ� �������� static ������ ���ٰ���
		cout << simObjCnt << "��° SoSimple ��ü" << endl;	
	}
};
int SoSimple::simObjCnt = 0;	// SoSimple�� ����� static ���� �ʱ�ȭ

class SoComplex
{
private:
	static int cmxObjCnt;
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "���� SoComplex ��ü" << endl;
	}
	SoComplex(SoComplex& copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "��° SoComplex ��ü" << endl;
	}
};
int SoComplex::cmxObjCnt = 0;	// SoComplex�� ����� static ���� �ʱ�ȭ

int main(void)
{
	SoSimple sim1;
	SoSimple sim2;

	SoComplex cmx1;
	SoComplex cmx2 = cmx1;
	SoComplex();
	return 0;
}