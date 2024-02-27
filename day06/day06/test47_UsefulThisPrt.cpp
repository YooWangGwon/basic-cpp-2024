// file : test47_UsefulThisPrt.cpp
// date : 240227
// desc : this 포인터 예제

#include <iostream>
using namespace std;

class TwoNumber
{
private:
	int num1;
	int num2;
public:
	TwoNumber(int num1, int num2)
	{
		this->num1 = num1; // this->num1 : 멤버변수, num1:매개변수
		this->num2 = num2; // this->num2 : 멤버변수, num2:매개변수
	}

	/*
	TwoNumber(int num1, int num2)
		: num1(num1), num2(num2)	// 멤버 이니셜라이저에서는 this 포인터를 사용할 수 없다
	{
		//empty
	}
	*/

	void ShowTwoNumber()
	{
		cout << this->num1 << endl;	// this 포인터를 사용함으로써, 멤버변수에 접근함을 명확히 함.
		cout << this->num2 << endl;
	}
};

int main(void)
{
	TwoNumber two(2, 4);
	two.ShowTwoNumber();
	return 0;
}