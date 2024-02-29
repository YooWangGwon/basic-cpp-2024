// file : test69_Mutable.cpp
// date : 240229
// desc : Mutable 키워드

#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num1;
	mutable int num2;	// num2를 mutable 선언 -> const 함수 내에서 변경 허용
public:
	SoSimple(int n1, int n2)
		: num1(1), num2(2)
	{  }
	void ShowSimpleData() const
	{
		cout << num1 << "," << num2 << endl;
	}
	void CopyToNum2() const
	{
		num2 = num1;	// const 함수 내에서 num2에 저장된 값을 num1의 값으로 변경 변경
	}
};

int main(void)
{
	SoSimple sm(1, 2);
	sm.ShowSimpleData();
	sm.CopyToNum2();
	sm.ShowSimpleData();
	return 0;
}