// file : test107_PointerOperatorOverloading
// date : 240306
// desc : 포인터 연산자 오버로딩

#include <iostream>
using namespace std;

class Number
{
private:
	int num;
public:
	Number(int n) : num(n){ }
	void ShowData() const { cout << num << endl; } 

	Number* operator->()
	{
		return this;	// 객체 자기자신의 주소rkqt 반환
	}

	Number& operator*()
	{
		return *this;	// 객체 자기자신을 참조 형태로 반환
	}
};

int main(void)
{
	Number num(20);
	num.ShowData();

	(*num) = 30;		// (num.operator*()) = 30; -> 객체 자기자신에게 30을 집어넣음
	num->ShowData();	// num이 포인터 변수처럼 사용됨
	(*num).ShowData();	// (num.operator*()).ShowData() -> 포인터에 들어가있는 객체 자기자신이 return 되므로 객체의 함수 호출방식으로 실행됨
	return 0;
}