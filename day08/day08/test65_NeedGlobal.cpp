// file : test65_NeedGlobal.cpp
// date : 240229
// desc : 전역변수가 필요한 상황

#include <iostream>
using namespace std;
		
int simObjCnt = 0;		// 전역변수 선언1
int cmxObjCnt = 0;		// 전역변수 선언2

class SoSimple
{
public:
	SoSimple()
	{
		simObjCnt++;	// 객체가 생성될 때 마다 simObjCnt가 1씩 증가
		cout << simObjCnt << "번째 SoSimple 객체" << endl;
	}
};

class SoComplex
{
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
	}
	SoComplex(SoComplex& copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
	}
};

int main(void)
{
	SoSimple sim1;
	SoSimple sim2;

	SoComplex com1;
	SoComplex com2 = com1;	// 복사생성자에 의한 객체 생성
	SoComplex();			// 임시객체 생성
	return 0;
}