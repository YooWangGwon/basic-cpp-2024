// file: mainTest.cpp
// date : 240311
// desc : 예외처리

# include <iostream>
using namespace std;

void calc(int a, int b)
{
	cout << "+: " << a + b << endl;
	cout << "-: " << a - b << endl;
	cout << "×: " << a * b << endl;
	cout << "÷: " << a / b << endl;
}

int main(int argc, char* argv[])
{
	int n1, n2;
	cout << " 정수 2개를 입력하세요: ";
	cin >> n1 >> n2;

	cout << "+: " << n1 + n2 << endl;
	cout << "-: " << n1 - n2 << endl;
	cout << "×: " << n1 * n2 << endl;

	try {	// 예외가 발생할 수 있는 부분을 try로 묶음
		if (!n2) throw n2;	// n2로 나눌 수 없다면, n2를 던져라
		cout << "÷: " << n1/n2 << endl;
	}

	catch (int exception)	// 정수형으로 예외가 발생했기 때문에 int exception
	{						// try는 catch와 따로 쓰일 수 없다.
		cout << "0으로 나눌 수 없습니다." << endl;
	}

	try {
		calc(n1, n2);
	}
	catch(int exception)
	{
		cout << "0으로 나눌 수 없습니다.";
	}

	return 0;
}