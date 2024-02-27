// file : test48_SelfRef.cpp
// date : 240227
// desc : Self-Reference�� ��ȯ(p.199~201)

// Self-Reference : ��ü �ڽ��� �����Ҽ� �ִ� ������

# include <iostream>
using namespace std;

class SelfRef
{
private:
	int num;
public:
	SelfRef(int n) : num(n)
	{
		cout << "��ü ����" << endl;
	}
	SelfRef& Adder(int n)
	{
		num += n;
		return *this; // this:��ü �ڱ��ڽ��� �ּҰ�, *this:��ü �ڱ��ڽ�, return *this: ��ü �ڱ��ڽ��� ����
	}
	SelfRef& ShowTwoNumber()
	{
		cout << num << endl;
		return *this;
	}
};

int main(void)
{
	SelfRef obj(3);	// obj ��ü ���� // ������ ����� ���ÿ� �ʱ�ȭ�ؾ���
	SelfRef& ref = obj.Adder(2); // obj�� ������� num�� ���ް� 2�� ���ϰ� ��ü �ڱ��ڽ��� ����, ���� ��ü ref�� ��ü �ڱ��ڽ��� ������

	obj.ShowTwoNumber();	//
	ref.ShowTwoNumber();

	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();
	return 0;
}