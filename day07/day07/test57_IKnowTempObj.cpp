// file : test57_IKnowTempObj.cpp
// date : 240228
// desc : 임시객체

#include <iostream>
using namespace std;

class Temporary
{
private:
	int num;
public:
	Temporary(int n) : num(n)
	{
		cout << "create obj: " << num << endl;
	}
	~Temporary()
	{
		cout << "destroy obj: " << num << endl;
	}
	void ShowTempInfo()
	{
		cout << "My num is " << num << endl;
	}
};

int main(void)
{
	Temporary(100);	// 100으로 초기화된 Temporary 타입의 이름없는 임시객체 생성
	cout << "********** after make!" << endl << endl;

	Temporary(200);	// 200으로 초기화된 Temporary 타입의 이름없는 임시객체를 생성하고 이 객체를 대상으로 ShowTempInfo 함수를 호출
	cout << "********** after make!" << endl << endl;

	const Temporary& ref = Temporary(300);				// 300으로 초기화된 Temporary 타입의 이름없는 임시객체를 생성하고 참조자 ref로 이 임시객체를 참조. 
	cout << "********** after make!" << endl << endl;	// 임시객체는 참조가 불가능하지만 const 키워드를 붙여서 상수화시키면(메모리에 할당됨) 참조가 가능해짐
	return 0;
}