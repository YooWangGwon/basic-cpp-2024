// file : test11.cpp
// date : 20240221
// desc : 테스트

#include <iostream>

using namespace std;

// 함수선언


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

// 메인함수

int main()
{
	int val1, val2;
	int result = 0;
	cout << "두 정수를 입력하세요.(띄어쓰기로 구분) : ";
	cin >> val1 >> val2;

	char val4 = 0;
	cout << "연산자를 입력하세요.(+,-,*,/), : ";
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