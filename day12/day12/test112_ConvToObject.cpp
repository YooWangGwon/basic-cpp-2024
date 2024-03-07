// file : test112_ConvToObject.cpp
// date : 240307
// desc : 임시객체로의 자동 형 변환과 형 변환 연산자(Conversion Operator)(p.489~492)

#include <iostream>
using namespace std;

class Number
{
private:
	int num;
public:
	Number(int n = 0) : num(n)
	{
		cout << "Number(int n=0)" << endl;
	}
	Number& operator=(const Number& ref)	// 대입 연산자 오버로딩
	{
		cout << "operator=()" << endl;
		num = ref.num;
		return *this;
	}
	void ShowNumber() { cout << num << endl; }
};

int main(void)
{
	Number num;
	num = 30;	// 서로 다른 두 자료형(Number, Literal)의 피연산자를 대상으로 대입연산 진행(동일한 타입으로의 형변환 발생)
				// Literal(리터럴) : 코드에 직접 삽입된 값, 이 값은 변경할 수 없으므로 '상수'
				// Number형 객체가 와야할 자리에 int 데이터가 왔을 경우, Literal형 데이터를 인자로 전달받는 Number형 클래스의 생성자 호출을 통해서 Number형 임시객체를 생성
	num.ShowNumber();
	return 0;
}

/*
	int a= 10;
	int b= 0;
	double d = 3.14;
	a = d; (X)
	d = a; (O) -> upcasting은 가능
*/