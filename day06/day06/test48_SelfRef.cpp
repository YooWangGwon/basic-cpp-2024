// file : test48_SelfRef.cpp
// date : 240227
// desc : Self-Reference의 반환(p.199~201)

// Self-Reference : 객체 자신을 참조할수 있는 참조자

# include <iostream>
using namespace std;

class SelfRef
{
private:
	int num;
public:
	SelfRef(int n) : num(n)
	{
		cout << "객체 생성" << endl;
	}
	SelfRef& Adder(int n)
	{
		num += n;
		return *this; // this:객체 자기자신의 주소값, *this:객체 자기자신, return *this: 객체 자기자신을 리턴
	}
	SelfRef& ShowTwoNumber()
	{
		cout << num << endl;
		return *this;
	}
};

int main(void)
{
	SelfRef obj(3);	// obj 객체 생성 // 참조는 선언과 동시에 초기화해야함
	SelfRef& ref = obj.Adder(2); // obj의 멤버변수 num에 전달값 2를 더하고 객체 자기자신을 리턴, 이후 객체 ref에 객체 자기자신이 참조됨

	obj.ShowTwoNumber();	//
	ref.ShowTwoNumber();

	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();
	return 0;
}