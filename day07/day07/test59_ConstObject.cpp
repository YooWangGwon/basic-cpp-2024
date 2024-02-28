// file : test59_ConstObject.cpp
// date : 240228
// desc : const ��ü�� const ��ü�� Ư����(p.244~245)

#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{ }
	SoSimple& AddNum(int n)	// �Ϲ� ����Լ�
	{
		num += n;
		return *this;
	}
	void ShowData() const	// const ����Լ�
	{
		cout << "num : " << num << endl;
	}
};

int main(void)
{
	cout << "�Ϲ� ��ü ����" << endl;
	SoSimple obj1(7);	// �Ϲ� ��ü ����
	obj1.AddNum(23);	// �Ϲ� ��ü�̱⋚���� �Ϲ� ����Լ� ȣ�� ����
	obj1.ShowData();	// const�Լ��� �Ϲݰ�ü���� ȣ�� ���� 

	const SoSimple obj2(7); // const ��ü ����
	// obj.AddNum(20)	// ����Լ� Addnum�� const �Լ��� �ƴϱ� ������ const ��ü������ ȣ���� �Ұ�����.  �����͸� �������� �ʴ� �Լ��� ������ const �Լ��� �ƴ϶�� ȣ�� �Ұ���.
	obj2.ShowData();		// ����Լ� ShowData�� const �Լ��̱� ������ const ��ü���� ȣ���� ������
	return 0;
}