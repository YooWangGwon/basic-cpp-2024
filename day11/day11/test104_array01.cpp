// file : test104_array01.cpp
// date : 240306
// desc : 배열의 표현식

#include <iostream>

int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };		// int형 배열 선언
	int* parr = arr;					// 배열의 이름은 주소이다.

	printf("arr 주소: %p\n", arr);
	printf("arr 크기: %d\n", sizeof(arr));	// int 크기 4 byte X 방 개수(5) = 20 byte
	
	// 실행 할 때마다 주소값이 변경 -> 실행될 때 마다 다른 메모리 공간을 할당 받기 때문
	printf("arr[0] 주소: %p\n", &arr[0]);	// arr[0]의 앞에 주소 연산자를 붙여 arr 0번방의 주소를 출력
	printf("arr[1] 주소: %p\n", &arr[1]);	// arr[1]의 앞에 주소 연산자를 붙여 arr 1번방의 주소를 출력
	printf("arr + 1:%p\n", arr + 1);		// arr + 1의 주소값과 arr[1]의 주소값은 동일 -> 같은 방, 같은 의미

	printf("parr 주소: %p\n", &parr);	// 포인트 변수 parr의 주소
	printf("parr 데이터 : %p\n", parr);	// parr이 가리키는 배열 arr의 주소를 저장
	printf("parr+1 : %p\n", parr + 1);	// 배열 arr의 1번방의 주소와 동일
	printf("parr[0]:%d\t *pa: %d\t arr[0]: %d\n", parr[0], *parr, arr[0]);


	return 0;
}