// file : test46_PointerThis.cpp
// date : 200227
// desc : this 포인터

# include<iostream>
# include<cstring>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int num)
	{
		this->num = num;	// this도 포인터이기 때문에 애로우 연산자 사용
		cout << "num=" << num << ",";
		cout << "address=" << this << endl; // this : 객체 자기자신을 가리킴
	
	}
	void ShowSimpleData()
	{
		cout << num << endl;
	}
	SoSimple* GetThisPointer()
	{
		return this;	// 객체 자기자신의 주소(포인터)를 반환
	}
};

int main(void)
{
	SoSimple sim1(100);
	SoSimple* ptr1 = sim1.GetThisPointer();		// 객체 sim1에 의해 반환된 this를 ptr1에 저장
	cout << ptr1 << ",";		// 멤버함수는 첫번째 객체를 생성할 때 정적 데이터 영역에 생성됨. 이후 두번째 생성된 객체는 첫번째 객체가 생성될때 생성한 영역을 공유함
	ptr1->ShowSimpleData();

	SoSimple sim2(200);
	SoSimple* ptr2 = sim2.GetThisPointer();
	cout << ptr2 << ",";
	ptr2->ShowSimpleData();
	return 0;
}