// file : test14_NewDelete.cpp
// date : 240223
// desc : New와 Delete

#include <iostream>
#include <string.h>

using namespace std;

char* MakeStrAdr(int len) 
{
	// char * str=(char *)malloc(sizeof(char) *len);
	char* str = new char[len]; // C++ : 힙영역에 len 크기만큼 메모리 공간 할당하여 객체를 생성. Stack에서 포인트 변수를 만들어 heap영역의 메모리 주소를 저장
	return str;
}

int main(void)
{
	char* str = MakeStrAdr(20);
	strcpy(str, "I am so happy~");
	cout << str << endl;
	// free(str)
	delete[]str; // C++: 할당받은 메모리 반환
	return 0;
}