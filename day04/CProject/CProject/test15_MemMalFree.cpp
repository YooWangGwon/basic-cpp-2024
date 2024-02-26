// file : test15_MemMalFree.cpp
// date : 240223 
// desc : MemMalFree.cpp (p.91)

# include <iostream>
# include <string.h> // C언어의 헤더파일1 : C 형식 문자열 (널 종료 문자열) 을 다룰 수 있는 함수들을 포함
# include <stdlib.h> // C언어의 헤더파일2 : 문자열 변환, 의사 난수 생성, 동적 메모리 관리 등의 함수들을 포함

using namespace std;

char * MakeStrAdr(int len)
{
	char * str = (char*)malloc(sizeof(char) * len); // C:heap 영역에 20Byte 크기로 메모리를 할당받음 -> stack에 str이라는 포인트 변수를 만들어서 heap영역에 저장되어 있는 주소값을 저장시킴  
	printf("char size: %llu\n", sizeof(char));
	return str; // heap영역에 있는 주소값을 저장하고 있는 str을 return
}

int main(void)
{
	char * str = MakeStrAdr(20);
	strcpy(str, "I am so happy~"); // "I am so happy"를 str에 집어넣는다
	cout << str << endl;
	free(str);
	return 0;
}

/*

strcpy() — 스트링 복사

#include <string.h>
char *strcpy(char *string1, const char *string2);

strcpy() 함수는 끝나는 널 문자를 포함하여 string2를 string1에서 지정한 위치로 복사
*/