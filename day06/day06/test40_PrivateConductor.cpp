// file : test40_PrivateConductor.cpp
// date : 240227
// desc : Private 생성자

#include <iostream>
using namespace std;

class AAA
{
private:
	int num;

	AAA(int n) : num(n) {} // 외부에서의 객체 생성을 막음, 싱글톤 디자인:객체생성을 단 하나만 할 때 사용하는 디자인 패턴(메모리 절약, 객체가 가지는 변수를 공유하는게 필요한 경우)

public:
	AAA() : num(0) {} // public에서 default 생성자 정의 -> 클래스 외부에서는 아래 생성자를 기반으로 객체를 생성

	AAA& CreatInitObj(int n) const // 함수 내에서, 17행에 정의된 private 생성자를 이용해서 AAA 객체를 생성 및 반환 
	{
		AAA* ptr = new AAA(n); // new 연산자를 통해 private에 있는 생성자를 실행하여 힙영역에서 객체를  생성 -> AAA타입의 포인터 변수에 대입
		return *ptr;
	}
	void ShowNum() const { cout << num << endl; }
};

int main(void)
{
	AAA base; // 싱글톤 특정 클래스의 인스턴스를 1개만 생성되는 것을 보장하는 디자인 패턴
	base.ShowNum();	

	AAA& obj1 = base.CreatInitObj(3); // AAA타입의 참조변수 obj1
	obj1.ShowNum();

	AAA& obj2 = base.CreatInitObj(12); // AAA타입의 참조변수 obj2
	obj2.ShowNum();
	// obj1과 obj2는 별도의 객체
	delete &obj1; // obj1 반환
	delete &obj2; // obj2 반환
	return 0;
}