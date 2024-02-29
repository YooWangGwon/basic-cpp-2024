// file : test66_StaticMember.cpp
// date : 240229
// desc : static 멤버변수(클래스 변수)

#include <iostream>
using namespace std;

class SoSimple
{
private:
	static int simObjCnt;	// private이기 때문에 외부에서의 접근을 차단
public:
	SoSimple()
	{
		simObjCnt++;										// 멤버변수처럼 멤버함수 내에서만 static 변수에 접근가능
		cout << simObjCnt << "번째 SoSimple 객체" << endl;	
	}
};
int SoSimple::simObjCnt = 0;	// SoSimple에 선언된 static 변수 초기화

class SoComplex
{
private:
	static int cmxObjCnt;
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번재 SoComplex 객체" << endl;
	}
	SoComplex(SoComplex& copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
	}
};
int SoComplex::cmxObjCnt = 0;	// SoComplex에 선언된 static 변수 초기화

int main(void)
{
	SoSimple sim1;
	SoSimple sim2;

	SoComplex cmx1;
	SoComplex cmx2 = cmx1;
	SoComplex();
	return 0;
}