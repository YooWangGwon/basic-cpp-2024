#include<iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{ }
	SoSimple& Addnum(int n)
	{
		num += n;
		return *this;
	}
	void SimpleFunc()
	{
		cout << "SimpleFunc: " << num << endl;
	}
	void SimpleFunc() const
	{
		cout << "const SimpleFunc: " << num << endl;
	}
};

void YourFunc(const SoSimple& obj)	// ���޵Ǵ� ���ڸ� const �����ڷ� ����.
{
	obj.SimpleFunc();	// const�����ڷ� �ޱ� ������ const ����Լ��� ȣ���
}


int main(void)
{
	SoSimple obj1(2);		// �Ϲ� ��ü ����
	const SoSimple obj2(7);	// const ��ü ����

	obj1.SimpleFunc();	// �Ϲݰ�ü�� �Ϲ� ����Լ� ȣ��
	obj2.SimpleFunc();	// const��ü�� const ����Լ� ȣ��

	YourFunc(obj1);	
	YourFunc(obj2);
	return 0;
}