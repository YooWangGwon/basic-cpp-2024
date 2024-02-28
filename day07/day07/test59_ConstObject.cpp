// file : test59_ConstObject.cpp
// date : 240228
// desc : const 객체와 const 객체의 특성들(p.244~245)

#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{ }
	SoSimple& AddNum(int n)	// 일반 멤버함수
	{
		num += n;
		return *this;
	}
	void ShowData() const	// const 멤버함수
	{
		cout << "num : " << num << endl;
	}
};

int main(void)
{
	cout << "일반 객체 생성" << endl;
	SoSimple obj1(7);	// 일반 객체 생성
	obj1.AddNum(23);	// 일반 객체이기떄문에 일반 멤버함수 호출 가능
	obj1.ShowData();	// const함수라도 일반객체에서 호출 가능 

	const SoSimple obj2(7); // const 객체 생성
	// obj.AddNum(20)	// 멤버함수 Addnum은 const 함수가 아니기 때문에 const 객체에서는 호출이 불가능함.  데이터를 변경하지 않는 함수라 할지라도 const 함수가 아니라면 호출 불가능.
	obj2.ShowData();		// 멤버함수 ShowData는 const 함수이기 떄문에 const 객체에서 호출이 가능함
	return 0;
}