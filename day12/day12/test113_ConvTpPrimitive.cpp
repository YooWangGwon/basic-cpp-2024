// file : test112_ConvToObject.cpp
// date : 240307
// desc : 임시객체로의 자동 형 변환과 형 변환 연산자(Conversion Operator)(p.492~493)

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
	Number& operator=(const Number& ref)
	{
		cout << "operator=()" << endl;
		num = ref.num;
		return *this;
	}
	operator int()	// 형 변환 연산자 오버로딩, 기본적인 형변환 연산자는 값을 반환하지 않는다.
	{
		cout << "operator int()" << endl;
		return num;
	}
	void ShowNumber() { cout << num << endl; }
};

int main(void)
{
	Number num1;
	num1 = 30;
	Number num2 = num1 + 20;
	num2.ShowNumber();
	return 0;
}