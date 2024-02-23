// file : test12
// date : 20240223
// desc : const

#include <iostream>

int main()
{
	const int num = 10;	 //const:const int라고하면 int 타입이 아닌 별도의 const int라는 타입이 생겨난다
	//int& ref = num;	// 그냥 int 타입으로 할 경우 타입 불일치 발생
	const int& ref =num
	// const 키워드가 붙으면 상수도 참조할 수 있다.(임시변수를 만들어서 상수를 저장하고 주소를 할당)
	// 레지스터(Register) :  레지스터는 컴퓨터의 중앙 처리 장치(CPU) 내부에 있는 매우 빠른 메모리 장치
	// 변수를 레지스터에 저장한 후에 사용


}