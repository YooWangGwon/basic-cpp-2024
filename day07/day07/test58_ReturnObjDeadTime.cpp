#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{
		cout << "New Object: " << this << endl; // 객체 생성시 주소를 출력
	}
	SoSimple(const SoSimple& copy) : num(copy.num) // copy로 전달되는 객체의 num을 복사해서 입력
	{
		cout << "New Copy obj: " << this << endl;	// 복사한 객체 생성시 주소를 출력
	}
	~SoSimple()
	{
		cout << "Destroy obj: " << this << endl;
	}
};

SoSimple SimpleFuncObj(SoSimple ob)	// 객체 ob는 객체 obj를 복사해서 생성됨
{
	cout << "Parm ADR: " << &ob << endl; // 선언하는 위치에 있지않는 &연산자는 대상의 주소를 의미한다.-> 객체 ob의 주소를 구하는 코드
	return ob;	// 임시객체 생성
} // 함수가 끝나면 매개변수 ob가 소멸되고 생성된 임시객체도 받아서 사용하는 코드가 없으면 소멸됨

int main(void) 
{
	SoSimple obj(7);	// 객체 생성
	SimpleFuncObj(obj);	// 함수 호출로 인한 복사 생성자의 매개변수이자 지역변수인 객체 ob생성

	cout << endl;
	SoSimple tempRef = SimpleFuncObj(obj);	// tempRef라는 객체를 생성하는 것이 아닌 tempRef에 임시객체를 저장
	cout << "Return Obj" << &tempRef << endl;	// 임시객체의 주소 출력
	return 0;	// 객체 obj 소멸
}

/*
New Object: 0000004896EFF5F4 -> 객체 obj의 주소
New Copy obj: 0000004896EFF6F4 -> 객체 ob의 주소
Parm ADR: 0000004896EFF6F4 -> 객체 ob의 주소
New Copy obj: 0000004896EFF734 -> 임시객체의 주소
Destroy obj: 0000004896EFF6F4 -> 객체 ob 소멸
Destroy obj: 0000004896EFF734 -> 임시객체 소멸

New Copy obj: 0000004896EFF754 -> 객체 ob의 생성 및 주소 
Parm ADR: 0000004896EFF754	-> 객체 ob의 주소
New Copy obj: 0000004896EFF614 -> 임시객체 생성 및 그 주소
Destroy obj: 0000004896EFF754 -> 객체 ob 소멸
Return Obj0000004896EFF614 -> tempRef라는 이름을 가진 임시객체의 주소
Destroy obj: 0000004896EFF614 -> 임시객체 소멸
Destroy obj: 0000004896EFF5F4 -> 객체 obj 소멸
*/