// file : test02_HelloWorld
// date : 20240221
// desc : HelloWorld.cpp (p.14)

#include <iostream> // 기본 입출력과 관련된 cout, cin, endl등을 제공

/*
문자 : 글자 한개(작은따옴표('')에 넣어서 표현)
문자열 : 두개이상의 글자(큰따옴표("")에 넣어서 표현)
파이썬에서처럼 작은따옴표와 큰따옴표를 혼용할 수 없다
*/

/*
int main(void)
{
	int num = 20; // 메모리 공간(RAM)에 int크기로 저장공간을 할당받고 num이름으로 사용하는 변수에 20이라는 값을 집어넣는다
	std::cout << "Hello World!" << std::endl; // :: -> 범위연산자(ex. std::cout std안에 속하는 cout)
	std::cout << "Hello" << "World" << std::endl; // << 연산자 : "Hello"를 std::cout에 넣어서 출력(cout:화면에 데이터를 출력)
	std::cout << num << ' ' << 'A'; // endl이 없을 경우 이어서 출력
	std::cout << ' ' << 3.14 << std::endl; //endl : 한줄을 띄운다
	return 0;
}
*/