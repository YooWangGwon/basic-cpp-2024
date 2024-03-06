// file : test107_PointerOperatorOverloading
// date : 240306
// desc : ������ ������ �����ε�

#include <iostream>
using namespace std;

class Number
{
private:
	int num;
public:
	Number(int n) : num(n){ }
	void ShowData() const { cout << num << endl; } 

	Number* operator->()
	{
		return this;	// ��ü �ڱ��ڽ��� �ּ�rkqt ��ȯ
	}

	Number& operator*()
	{
		return *this;	// ��ü �ڱ��ڽ��� ���� ���·� ��ȯ
	}
};

int main(void)
{
	Number num(20);
	num.ShowData();

	(*num) = 30;		// (num.operator*()) = 30; -> ��ü �ڱ��ڽſ��� 30�� �������
	num->ShowData();	// num�� ������ ����ó�� ����
	(*num).ShowData();	// (num.operator*()).ShowData() -> �����Ϳ� ���ִ� ��ü �ڱ��ڽ��� return �ǹǷ� ��ü�� �Լ� ȣ�������� �����
	return 0;
}