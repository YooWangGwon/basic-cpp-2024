// file : test56_ReturnObjCopyCon.cpp
// date : 240228
// desc : ��ü�� ��ȯ�ϵ�, ���������� ��ȯ���� �ʴ� ���

#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{ }
	SoSimple(const SoSimple& copy) : num(copy.num)
	{
		cout << "Called SoSimple(const SoSimple& copy)" << endl;
	}
	SoSimple& AddNum(int n)
	{
		num += n;	// num = num + n, num = 7 + 30
		return *this;	// ������ �����ϴ� ��ü �ڽ��� ��ȯ. ��ȯ���� �������̴� �������� ��ȯ��
	}
	void ShowData()
	{
		cout << "num: " << num << endl;
	}
};

SoSimple SimpleFuncObj(SoSimple ob) // ������ ���ް������� ���� �����ڰ� ȣ���
{
	cout << "return ����" << endl;
	return ob;	// ob ��ü�� ��ȯ. �������� �ƴϹǷ� ob��ü�� ���纻�� ��������鼭 ��ȯ -> ��������ڰ� �߰��� ȣ���
}

int main(void)
{
	SoSimple obj(7);
	SimpleFuncObj(obj).AddNum(30).ShowData();	// SimpleFuncObj �Լ��� ��ȯ�� ��ü ob�� ������� AddNum�Լ��� ȣ���ϰ�, �̾ AddNum �Լ��� ��ȯ�ϴ� �������� ������� ShowData �Լ��� ȣ��
	obj.ShowData();								// SimpleFuncObj(obj)���� ��ȯ���� ob��ü�� ���������̱� ������ SimpleFuncObj�Լ��� ����� �����. 
	return 0;									// �̶����� ob��ü�� ������ �̸����� �ӽð�ü�� ����(��������� ȣ��)�Ͽ� ������ �Լ����� ���
}