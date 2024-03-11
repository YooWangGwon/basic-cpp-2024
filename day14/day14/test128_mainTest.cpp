// file: mainTest.cpp
// date : 240311
// desc : ����ó��

# include <iostream>
using namespace std;

void calc(int a, int b)
{
	cout << "+: " << a + b << endl;
	cout << "-: " << a - b << endl;
	cout << "��: " << a * b << endl;
	cout << "��: " << a / b << endl;
}

int main(int argc, char* argv[])
{
	int n1, n2;
	cout << " ���� 2���� �Է��ϼ���: ";
	cin >> n1 >> n2;

	cout << "+: " << n1 + n2 << endl;
	cout << "-: " << n1 - n2 << endl;
	cout << "��: " << n1 * n2 << endl;

	try {	// ���ܰ� �߻��� �� �ִ� �κ��� try�� ����
		if (!n2) throw n2;	// n2�� ���� �� ���ٸ�, n2�� ������
		cout << "��: " << n1/n2 << endl;
	}

	catch (int exception)	// ���������� ���ܰ� �߻��߱� ������ int exception
	{						// try�� catch�� ���� ���� �� ����.
		cout << "0���� ���� �� �����ϴ�." << endl;
	}

	try {
		calc(n1, n2);
	}
	catch(int exception)
	{
		cout << "0���� ���� �� �����ϴ�.";
	}

	return 0;
}