// file : test47_UsefulThisPrt.cpp
// date : 240227
// desc : this ������ ����

#include <iostream>
using namespace std;

class TwoNumber
{
private:
	int num1;
	int num2;
public:
	TwoNumber(int num1, int num2)
	{
		this->num1 = num1; // this->num1 : �������, num1:�Ű�����
		this->num2 = num2; // this->num2 : �������, num2:�Ű�����
	}

	/*
	TwoNumber(int num1, int num2)
		: num1(num1), num2(num2)	// ��� �̴ϼȶ����������� this �����͸� ����� �� ����
	{
		//empty
	}
	*/

	void ShowTwoNumber()
	{
		cout << this->num1 << endl;	// this �����͸� ��������ν�, ��������� �������� ��Ȯ�� ��.
		cout << this->num2 << endl;
	}
};

int main(void)
{
	TwoNumber two(2, 4);
	two.ShowTwoNumber();
	return 0;
}