// file : 221_04
// date : 20240221
// desc : �ݺ���� - for

#include <iostream>

using namespace std;

// int sum; -> ���������� ������ ��� �ڵ����� 0���� �ʱ�ȭ������ �����Ͱ� ����(�ջ�)�� Ȯ���� ���� ������ �������̸� ������� �ʴ� ���� ����.

int main() 
{
	int sum=0; // sum�� ���� : ������ �������� �������ִ� ���� -> �ʱ�ȭ ������ �ʼ�!

	for (int i = 1; i <= 100; i++) {
		// sum += i;
		sum = sum + i;
	}
	cout << sum << endl;

	return 0;
}