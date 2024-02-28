// file : test57_IKnowTempObj.cpp
// date : 240228
// desc : �ӽð�ü

#include <iostream>
using namespace std;

class Temporary
{
private:
	int num;
public:
	Temporary(int n) : num(n)
	{
		cout << "create obj: " << num << endl;
	}
	~Temporary()
	{
		cout << "destroy obj: " << num << endl;
	}
	void ShowTempInfo()
	{
		cout << "My num is " << num << endl;
	}
};

int main(void)
{
	Temporary(100);	// 100���� �ʱ�ȭ�� Temporary Ÿ���� �̸����� �ӽð�ü ����
	cout << "********** after make!" << endl << endl;

	Temporary(200);	// 200���� �ʱ�ȭ�� Temporary Ÿ���� �̸����� �ӽð�ü�� �����ϰ� �� ��ü�� ������� ShowTempInfo �Լ��� ȣ��
	cout << "********** after make!" << endl << endl;

	const Temporary& ref = Temporary(300);				// 300���� �ʱ�ȭ�� Temporary Ÿ���� �̸����� �ӽð�ü�� �����ϰ� ������ ref�� �� �ӽð�ü�� ����. 
	cout << "********** after make!" << endl << endl;	// �ӽð�ü�� ������ �Ұ��������� const Ű���带 �ٿ��� ���ȭ��Ű��(�޸𸮿� �Ҵ��) ������ ��������
	return 0;
}