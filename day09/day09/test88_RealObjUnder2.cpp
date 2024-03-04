// file : test88_RealObjUnder2.cpp
// date : 240304
// desc : ��� �Լ��� ���ۿ���

#include <iostream>
using namespace std;

typedef struct Data
{
	int data;
	void (*ShowData)(Data*);	// �Լ��� ������ ������ ����ü�� ����� ����. �Լ��̸� �տ� ������(*)�� ���� ���, �Լ��� �ּҸ� �ǹ�
	void(*Add)(Data*, int);		// ����ο����� �Ű����� �̸� ��������. ���⼭ �Լ��� ��������� ���� �ƴ� �Լ��� ��ġ�� �����ϰ� �ִ�.
} Data; // struct Data �� Data�� ����Ͽ� ���


void ShowData(Data* THIS)	// Data ����ü �����ͺ��� THIS�� �Է����� ����. ���Ǻο����� �Ű����� �̸� ���� �Ұ���
{							// ��� ������ ��ü���� ���������� ����Լ��� ����. ���� �����ߴ��� �����ϱ� ���� THIS �����͸� ���
	cout << "Data: " << THIS->data << endl; // ShowData ��� �Լ� ����
}
void Add(Data* THIS, int num) 
{ 
	THIS->data += num;						// Add ��� �Լ� ����
}

int main(void)
{
	Data obj1 = { 15, ShowData, Add };	// Data ����ü ���� obj1 ����� �ʱ�ȭ
	Data obj2 = { 7,ShowData,Add };		// Data ����ü ���� obj2 ����� �ʱ�ȭ
										// ������ ��ü�� �Լ��� �����ϰ� �ִ°� �ƴ� �Լ��� �ϳ��� �����ϰ� ��ü���� ����.
	obj1.Add(&obj1, 17); // ����ü obj1�� ������(�ּ�)�� ���� 17�� �Է�
	obj2.Add(&obj2, 9);
	obj1.ShowData(&obj1);	// 32
	obj2.ShowData(&obj2);	// 16
	return 0;
}	
// �Ϲ����� �Լ��� ��� ȣ�������
// �����Լ��� �����Լ� ���̺��� ���ļ� �Լ��� ȣ��Ǳ� ������ �ӵ��� ���� ������