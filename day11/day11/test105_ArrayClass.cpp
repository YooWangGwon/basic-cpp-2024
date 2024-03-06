# include<iostream>
#include<cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
	int* arr;
	int arrlen;
public:
	BoundCheckIntArray(int len) : arrlen(len)
	{
		printf("������ ȣ��\n");
		arr = new int[len];			// heap  ������ �޸� ���� �Ҵ�
	}
	int& operator[] (int idx)
	{
		printf("[]������ �Լ� ȣ��\n");
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;	// ������ �� ���� �����϶� ���
			BoundCheckIntArray::~BoundCheckIntArray();	// �������� �Ǳ� �� �޸� ������ ��ȯ. �� �ڵ带 �Է����� ������ �޸𸮰� ��ȯ���� �ʰ� ���������
			exit(1);	// ���� ����
		}
		return arr[idx];
	}
	~BoundCheckIntArray()
	{
		printf("�Ҹ��� ȣ��\n");
		delete[]arr;	// �޸� ���� ��ȯ
	}
};

int main(void)
{
	BoundCheckIntArray arr(5);
	for (int i = 0; i < 5; i++)	// 5�� ����
		arr[i] = (i + 1) * 11;	// 0���� ���� �����ؼ� ���� 11�� ���̸鼭 �ְ� ����
	for (int i = 0; i < 6; i++)	// 6�� ����
		cout << arr[i] << endl;	// 6��°���� "Array index out of bound exception" ���

	return 0;
}