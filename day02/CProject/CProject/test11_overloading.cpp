// file : test11.cpp
// date : 20240221
// desc : �׽�Ʈ

#include <iostream>

using namespace std;

// �Լ�����


int add(int a, int b){
	return a + b;
}

int sub(int a, int b){
	return a - b;
}

int multi(int a, int b) {
	return a * b;
}

int divide(int a, int b) {
	return a / b;
}

// �����Լ�

int main()
{
	int val1, val2;
	int result = 0;
	cout << "�� ������ �Է��ϼ���.(����� ����) : ";
	cin >> val1 >> val2;

	char val4 = 0;
	cout << "�����ڸ� �Է��ϼ���.(+,-,*,/), : ";
	cin >> val4;

	if (val4 == '+') {
		result = add(val1, val2);
		cout << result << endl;
	}

	if (val4 == '-') {
		result = sub(val1, val2);
		cout << result << endl;
	}

	if (val4 == '*') {
		result = multi(val1, val2);
		cout << result << endl;
	}

	if (val4 == '/') {
		result = divide(val1, val2);
		cout << result << endl;
	}
	
	return 0;
}