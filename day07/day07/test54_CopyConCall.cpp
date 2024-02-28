// file : test54_CopyConCall.cpp
// date : 240228
// desc : 복사생성자의 호출 시점(p.227~229)

#include <iostream>

int func(int a)	// a = 10; num의 10을 복사해서 사용한다.(num의 10과 a의 10은 별개)
{
	a = 10 + a;
	return a;	// a를 리턴한다 ->  객체를 반환하되  참조형으로 반환하지 않는경우
				// 함수가 값을 반환하면 별도의 메모리 공간이 할당되고 이 공간에 값이 레지스트리에 임시적으로 저장된다.
}


int num = 10;
int b = func(num); // -> Call - by -value 방식의 함수호출 과정에서 객체를 인자로 전달하는 경우
int res = func(num); // res = 20, a의 값을 복사해서 res에 집어넣음(res의 20과 a의 20은 별개)