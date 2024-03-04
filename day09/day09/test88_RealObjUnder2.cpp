// file : test88_RealObjUnder2.cpp
// date : 240304
// desc : 멤버 함수의 동작원리

#include <iostream>
using namespace std;

typedef struct Data
{
	int data;
	void (*ShowData)(Data*);	// 함수의 포인터 변수가 구조체의 멤버로 등장. 함수이름 앞에 포인터(*)가 있을 경우, 함수의 주소를 의미
	void(*Add)(Data*, int);		// 선언부에서는 매개변수 이름 생략가능. 여기서 함수가 만들어지는 것이 아닌 함수의 위치를 저장하고 있다.
} Data; // struct Data 를 Data로 축약하여 사용


void ShowData(Data* THIS)	// Data 구조체 포인터변수 THIS를 입력으로 받음. 정의부에서는 매개변수 이름 생략 불가능
{							// 멤버 변수는 객체마다 소유하지만 멤버함수는 공유. 누가 접근했는지 구분하기 위해 THIS 포인터를 사용
	cout << "Data: " << THIS->data << endl; // ShowData 멤버 함수 정의
}
void Add(Data* THIS, int num) 
{ 
	THIS->data += num;						// Add 멤버 함수 정의
}

int main(void)
{
	Data obj1 = { 15, ShowData, Add };	// Data 구조체 변수 obj1 선언과 초기화
	Data obj2 = { 7,ShowData,Add };		// Data 구조체 변수 obj2 선언과 초기화
										// 각각의 객체가 함수를 보유하고 있는게 아닌 함수는 하나만 생성하고 객체들이 공유.
	obj1.Add(&obj1, 17); // 구조체 obj1의 포인터(주소)와 정수 17을 입력
	obj2.Add(&obj2, 9);
	obj1.ShowData(&obj1);	// 32
	obj2.ShowData(&obj2);	// 16
	return 0;
}	
// 일반적인 함수는 즉시 호출되지만
// 가상함수는 가상함수 테이블을 거쳐서 함수가 호출되기 때문에 속도가 비교적 느리다