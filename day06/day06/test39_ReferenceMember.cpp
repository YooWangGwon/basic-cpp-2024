// file : test39_ReferenceMember.cpp
// date : 240227
// desc : 멤버변수로 참조자 선언

# include <iostream>
using namespace std;

class AAA
{
public:
	AAA()
	{
		cout << "empty object" << endl; // 객체 생성 여부 확인 문구
	}
	void ShowYourName()
	{
		cout << "I'm class AAA" << endl;
	}
};

class BBB
{
private:
	AAA& ref;		//참조자가 멤버변수로 선언됨 -> 이니셜라이저 사용 
	const int& num; //const 참조자가 멤버변수로 선언됨 -> 이니셜라이저 사용 

public:
	BBB(AAA& r, const int& n)  
		: ref(r), num(n)		// 이니셜라이저 사용	
	{
	}
	void ShowYourName()
	{
		ref.ShowYourName();
		cout << "and" << endl;
		cout << "I ref num" << num << endl;
	}
};

int main(void)
{
	AAA obj1;
	BBB obj2(obj1, 20);
	obj2.ShowYourName();
	return 0;
}