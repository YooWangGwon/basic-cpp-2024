// file : test17_NewObject
// date : 240223
// desc : NewObject(p.94~95)

# include <iostream>
# include <stdlib.h>
using namespace std;

class Simple // 클래스 : int, char과 같은 또 다른 하나의 타입
{
public:
	Simple() // 생성자 : 클래스의 이름과 같은 method
	{
		cout << "I'm simple constructor!" << endl;
	}
};

int main(void)
{
	cout << "case 1: ";
	Simple* sp1 = new Simple; // new는 객체로 메모리를 할당받을 수 있음(사용자 정의 자료형으로도 메모리를 할당 받을 수 있음)
	// new 연산자를 이용해 heap영역에서 Simple이라는 변수에 메모리를 할당하고, Simple타입 sp1 포인터 변수를 stack에 만들어 heap의 메모리 주소를 저장 
	//Aaa *ap = new Aaa;

	cout << "case 2: ";
	Simple* sp2 = (Simple*)malloc(sizeof(Simple) * 1); // malloc은 기본타입(int,char)으로만 메모리를 할당받음
	// malloc 연산자를 이용해 heap영역에서 Simple이라는 변수에 메모리를 할당하고, Simple타입 sp2 포인터 변수를 stack에 만들어 heap의 메모리 주소를 저장 

	cout << endl << "end of main" << endl;
	delete sp1; // delete 연산자를 이용해 sp1에 대한 메모리 공간을 해제(객체 반환)
	free(sp2); // delete 연산자를 이용해 sp2에 대한 메모리 공간을 해제(객체 반환)
	return 0;
}
