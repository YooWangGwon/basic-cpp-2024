// file : test35_Constructor2.cpp
// date : 240226
// desc : Constructor2(p.172~173)

#include <iostream>
using namespace std;

class SimpleClass
{
private:
	int num1;
	int num2;
public:
	SimpleClass(int n1 = 0, int n2 = 0)
	{
		num1 = n1;
		num2 = n2;
	}
	void ShowData() const
	{
		cout << num1 << ' ' << num2 << endl;
	}
};

int main(void)
{
	SimpleClass sc1(); // 함수의 원형 선언
	SimpleClass mysc = sc1(); // sc1()의 리턴값인 객체 sc가 같은 타입인 mysc에 대입
	mysc.ShowData(); // 20 30 출력
	return 0; // 메인함수 종료
}

SimpleClass sc1()
{
	SimpleClass sc(20, 30); // 입력 2개를 받는 SimpleClass 타입의 sc 객체 생성
	return sc; // 객체 sc를 리턴
}