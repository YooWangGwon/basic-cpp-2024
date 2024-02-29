#include <iostream>
using namespace std;

class SoSimple
{
public:							// ���� ���� public
	static int simObjCnt;		// static ������� ����(Ŭ���� ���)
public:
	SoSimple()
	{
		simObjCnt++;
	}
};
int SoSimple::simObjCnt = 0;	// static ��������� �ʱ�ȭ

int main(void)
{
	cout << SoSimple::simObjCnt << "��° SoSimple ��ü" << endl;	// ��ü�� �ϳ��� �������� ���� ����. public���� ����� static����� ��𼭵� ������ ����
	SoSimple sim1;
	SoSimple sim2;

	cout << SoSimple::simObjCnt << "��° SoSimple ��ü" << endl;	// static ��������� Ŭ���������̱� ������ Ŭ���� ������ ������ ����. static ������ ���� ������� Ŭ���� ������ ������ �Ұ���
	cout << sim1.simObjCnt << "��° SoSimple ��ü" << endl;			
	cout << sim2.simObjCnt << "��° SoSimple ��ü" << endl;
	return 0;
}