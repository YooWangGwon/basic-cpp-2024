// file : test117_AddFuncTemplate.cpp
// date : 240307
// desc : 함수 템플릿

#include <iostream>
using namespace std;

template <typename T>	// 함수 템플릿
T Add(T num1, T num2)
{
	return num1 + num2;
}

int main(void)
{
	cout << Add<int>(15, 20) << endl;
	cout << Add<double>(2.9, 3.7) << endl;
	cout << Add<int>(3.2, 3.2) << endl;
	cout << Add<double>(3.14, 2.75) << endl;

	cout << Add(15, 20) << endl;	// 자료형을 쓰지 않더라도 컴파일 단계에서 입력값의 자료형을 토대로 자료형을 자동으로 결정
	cout << Add(2.9, 3.7) << endl;
	cout << Add(3.2, 3.2) << endl;
	cout << Add(3.14, 2.75) << endl;
	return 0;
}