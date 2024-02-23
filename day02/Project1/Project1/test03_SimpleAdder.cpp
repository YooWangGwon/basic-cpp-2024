// file : test03_SimpleAdder.cpp
// date : 20240221
// desc : SimpleAdder.cpp (p.17)

#include <iostream>

int global = 100; // 전역변수 : 프로그램의 시작과 동시에 메모리를 할당받고 프로그램이 종료됨과 동시에 메모리를 반납

void func() {
	int a = 100; // 지역변수 : func 함수가 시작되어야만 메모리를 할당받음, func함수에서만 사용 가능
}

/*
int main(void)
{
	int val1; // 메모리공간(RAM)에 int크기로 저장공간을 할당받고 val이름으로 사용한다,
	std::cout << "첫 번째 숫자 입력: ";
	std::cin >> val1; // cin : 데이터를 입력받는다,  >> 연산자 : cin에서 입력받은 값을 val1에 집어넣는다.

	int val2; // 지역변수 : main 함수가 시작되어야만 메모리를 할당받음
	std::cout << "두 번째 숫자 입력: ";
	std::cin >> val2;

	int result = val1 + val2;
	std::cout << "덧셈결과 : " << result << std::endl;
	return 0;

}

	지역변수(로컬변수) : 선언되어진 범위 안에서만 사용이 가능(static 영역에 저장)
	전역변수 : 프로그램 영역 어디에서든지 사용가능
*/
/*
int main()
{
	int val1, val2; // 같은 타입의 변수일 경우, 한줄에 같이 선언해도 된다.
	int result = 0; // 변수 선언과 동시에 값을 대입 : 변수 초기화
	std::cout << "두 개의 숫자 입력: ";
	std::cin >> val1 >> val2;
		
	if (val1 < val2)
	{
		for (int i = val1 + 1; i < val2;  i++)
			result += i;
	}
	else
	{
		for (int i = val2 + 1; i < val1; i++)
			result += i;
	}

	std::cout << "두 수 사이의 정수 합: " << result << std::endl;
	return 0;
}
*/
/*
제어문
	1. 선택제어문
		if, switch
	2. 반복제어문
		for(반복횟수 제한), while(무한반복)

	*for('초기식';'조건식';'증감식'){
		1. 초기식을 가지고 조건식을 따진다
		2. 참이면 for문의 실행문을 실행
		3. 증감식을 실행한다.
		4. 조건식을 따시고
		5. 2번의 행동
		6. 3번의 행동
		7. 조건식을 따지고
		8. 2번의 행동
	}
*/