// file : test42_dynamicA.cpp
// date : 240227
// desc : 메모리 동적 할당(new 연산자 사용)

// 동적 할당 : 실행 중에 메모리를 할당받는다.

#include <iostream>
using namespace std;

int main()
{
	cout << "int 크기 : " << sizeof(int) << endl;
	int *pi = new int;	// heap 공간에 int크기(4byte)만큼 메모리공간을 할당받고 할당받은 주소를 int타입으로 Return 
					    // 주소값이기 때문에 일반 변수가 아닌 포인터 변수(* pi)를 사용

	*pi = 10;	// *pi:포인터가 가리키는 곳의 저장공간을 의미 -> 저장공간에 10을 집어넣어라
	cout << "pi가 가리키는 곳에 저장된 값: " << *pi << endl;

	delete pi;	// heap 영역에 동적 할당받은 메모리 공간를 반환(반드시 반환!!), JAVA에서는 garbage collector가 자동으로 반환해줌.

	int *pary = new int[10];	  // 배열 형태로 할당
	cout << sizeof(pary) << endl; // 포인트 변수 자체의 크기는 8byte 
	for (int i = 0; i < 10; i++)
	{
		pary[i] = i + 10;	// 배열의 각 방에 원소(요소)값을 집어넣는다. ex) pary[0]=10
	}

	for (int i = 0; i < 10; i++)
	{
		printf("pary[%d] : %d\n", i, pary[i]);
	}

	delete[] pary; // 배열로 동적할당받은 메모미를 배열로 반환

	// new 연산자로 배열을 만드는 경우 생성자를 호출
	// int arr[10]처럼 배열을 만드는 경우 생성자를 호출하는 것이 아님


	return 0;
}