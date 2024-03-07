// file : test115_StringClass02.cpp
// date : 240307
// desc : C와 C++의 문자열

/*
C - Style 문자열
문자열은 마지막에 null 문자가 붙는다.
*/


#include <iostream>
using namespace std;

int main()
{
	printf("===C - Style 문자열===========================\n");

	int code = 97;
	cout << code << endl;
	cout << (char)code << endl;	// ascii 코드표에서 97이 a에 해당하기 때문

	cout << "==============================" << endl;
	char ary1[6] = { 'a','b','c','d','e' };		// 문자 타입의 배열 선언
	cout << ary1 << endl;

	printf("==============================\n");
	char ary2[] = { 'a','b','c','\0','e' };	// '\0' = null 문자 : 문자의 끝을 알려줌
	cout << ary2 << endl;
	cout << sizeof(ary2) << endl;	// 전체 문자의 크기 반환
	cout << strlen(ary2) << endl;	// null 문자 앞까지의 크기

	printf("==============================\n");
	char str[] = "string";	// 자동으로 맨 끝에 null 문자가 붙는다. Stack(스택)에 저장됨.
	cout << str << endl;
	cout << sizeof(str) << endl;	// 7 -> string에 null문자가 포함된 크기
	cout << strlen(str) << endl;	// 6 -> null 문자 앞까지의 크기
	str[0] = 'S';
	cout << str << endl;			// String

	printf("==============================\n");
	const char* pstr = "STRING";	// char * 만 있을 경우 error 발생. Data Segment에 저장됨.
	cout << pstr << endl;
	cout << sizeof(pstr) << endl;	// 8 -> 포인터 변수의 크기 : 64비트 운영체제 이기 때문에 주소 크기가 8byte
	cout << strlen(pstr) << endl;	// 6 -> null 문자 앞까지의 크기
	int a = 100;
	int* pa = &a;
	cout << sizeof(pa) << endl;		// 64비트에서 모든 포인터의 크기는 8byte
	// pstr[0] = 's';	// 문자열을 포인터로 사용하는 경우는 변경이 불가능 
						// -> 포인터 변수를 통해 저장된 STRING은 Data Segment에 저장되는데 Data Segment는 ReadOnly의 특징을 가져서 수정이 불가능하다.

	/*
	C++ - style : heap 영역에 저장
	*/
	printf("===C++ - Style 문자열=========================\n");

	string s = "string";
	cout << s << endl;
	cout << sizeof(s) << endl;	// 40(byte) - 기본적인 string 클래스 객체의 크기
	// cout << strlen(s) << endl;	// const char * 타입이기 때문에 사용 불가능
	cout << s.size() << endl;	// 6

	string s1 = "Yoo Wang Gwon";
	cout << s1 << endl;
	cout << sizeof(s1) << endl;	// 40(byte)
	cout << s1.size() << endl;	// 13 : 문자의 개수+띄어쓰기 개수

	return 0;
}