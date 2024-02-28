#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{
		cout << "New Object: " << this << endl; // ��ü ������ �ּҸ� ���
	}
	SoSimple(const SoSimple& copy) : num(copy.num) // copy�� ���޵Ǵ� ��ü�� num�� �����ؼ� �Է�
	{
		cout << "New Copy obj: " << this << endl;	// ������ ��ü ������ �ּҸ� ���
	}
	~SoSimple()
	{
		cout << "Destroy obj: " << this << endl;
	}
};

SoSimple SimpleFuncObj(SoSimple ob)	// ��ü ob�� ��ü obj�� �����ؼ� ������
{
	cout << "Parm ADR: " << &ob << endl; // �����ϴ� ��ġ�� �����ʴ� &�����ڴ� ����� �ּҸ� �ǹ��Ѵ�.-> ��ü ob�� �ּҸ� ���ϴ� �ڵ�
	return ob;	// �ӽð�ü ����
} // �Լ��� ������ �Ű����� ob�� �Ҹ�ǰ� ������ �ӽð�ü�� �޾Ƽ� ����ϴ� �ڵ尡 ������ �Ҹ��

int main(void) 
{
	SoSimple obj(7);	// ��ü ����
	SimpleFuncObj(obj);	// �Լ� ȣ��� ���� ���� �������� �Ű��������� ���������� ��ü ob����

	cout << endl;
	SoSimple tempRef = SimpleFuncObj(obj);	// tempRef��� ��ü�� �����ϴ� ���� �ƴ� tempRef�� �ӽð�ü�� ����
	cout << "Return Obj" << &tempRef << endl;	// �ӽð�ü�� �ּ� ���
	return 0;	// ��ü obj �Ҹ�
}

/*
New Object: 0000004896EFF5F4 -> ��ü obj�� �ּ�
New Copy obj: 0000004896EFF6F4 -> ��ü ob�� �ּ�
Parm ADR: 0000004896EFF6F4 -> ��ü ob�� �ּ�
New Copy obj: 0000004896EFF734 -> �ӽð�ü�� �ּ�
Destroy obj: 0000004896EFF6F4 -> ��ü ob �Ҹ�
Destroy obj: 0000004896EFF734 -> �ӽð�ü �Ҹ�

New Copy obj: 0000004896EFF754 -> ��ü ob�� ���� �� �ּ� 
Parm ADR: 0000004896EFF754	-> ��ü ob�� �ּ�
New Copy obj: 0000004896EFF614 -> �ӽð�ü ���� �� �� �ּ�
Destroy obj: 0000004896EFF754 -> ��ü ob �Ҹ�
Return Obj0000004896EFF614 -> tempRef��� �̸��� ���� �ӽð�ü�� �ּ�
Destroy obj: 0000004896EFF614 -> �ӽð�ü �Ҹ�
Destroy obj: 0000004896EFF5F4 -> ��ü obj �Ҹ�
*/