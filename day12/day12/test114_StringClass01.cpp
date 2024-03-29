// file : test114_StringClass01.cpp
// date : 240307
// desc : 표준 string 클래스(p.506~508)

# include <iostream>
# include <string>
using namespace std;

int main(void)
{
	string str1 = "I like ";
	string str2 = "string class";
	string str3 = str1 + str2;	// string 객체간 덧셈연산이 가능

	cout << str1 << endl;	// string 클래스가 << 연산자에 대해서도 오버로딩 되어있음
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;			// 문자열 str1의 끝에 문자열 str2가 덧붙여 졌음을 "동일 문자열!"의 출력을 통해 확인
	if (str1 == str3)
		cout << "동일 문자열!" << endl;
	else
		cout << "동일하지 않는 문자열!" << endl;

	string str4;
	cout << "문자열 입력: ";
	cin >> str4;			// string 클래스가 >> 연산자에 대해서도 오버로딩 되어있음
	cout << "입력한 문자열: " << str4 << endl;
	return 0;
}