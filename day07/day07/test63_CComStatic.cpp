// file : test63_CComStatic.cpp
// date : 240228
// desc : static����(��������)

#include <iostream>
using namespace std;

void Counter()
{
	static int cnt;	// ���� ������ ������ cnt ������ ���� �Ҵ� -> �Լ��� ������ �Լ��� ������� cnt ������ ������� �ʰ� ��� ��� -> Current cnt : 1���� 10���� ��µ� 
	// int cnt = 0;	// �Լ��� ������ cnt ������ ����� -> Current cnt : 1 ����� 10�� �ݺ���
	cnt++;
	cout << "Current cnt: " << cnt << endl;
}

int main(void)
{
	for (int i = 0; i < 10; i++)
		Counter();
	return 0;
}