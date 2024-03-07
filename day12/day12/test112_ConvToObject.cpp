// file : test112_ConvToObject.cpp
// date : 240307
// desc : �ӽð�ü���� �ڵ� �� ��ȯ�� �� ��ȯ ������(Conversion Operator)(p.489~492)

#include <iostream>
using namespace std;

class Number
{
private:
	int num;
public:
	Number(int n = 0) : num(n)
	{
		cout << "Number(int n=0)" << endl;
	}
	Number& operator=(const Number& ref)	// ���� ������ �����ε�
	{
		cout << "operator=()" << endl;
		num = ref.num;
		return *this;
	}
	void ShowNumber() { cout << num << endl; }
};

int main(void)
{
	Number num;
	num = 30;	// ���� �ٸ� �� �ڷ���(Number, Literal)�� �ǿ����ڸ� ������� ���Կ��� ����(������ Ÿ�������� ����ȯ �߻�)
				// Literal(���ͷ�) : �ڵ忡 ���� ���Ե� ��, �� ���� ������ �� �����Ƿ� '���'
				// Number�� ��ü�� �;��� �ڸ��� int �����Ͱ� ���� ���, Literal�� �����͸� ���ڷ� ���޹޴� Number�� Ŭ������ ������ ȣ���� ���ؼ� Number�� �ӽð�ü�� ����
	num.ShowNumber();
	return 0;
}

/*
	int a= 10;
	int b= 0;
	double d = 3.14;
	a = d; (X)
	d = a; (O) -> upcasting�� ����
*/