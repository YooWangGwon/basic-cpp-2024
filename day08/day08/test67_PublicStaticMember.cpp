#include <iostream>
using namespace std;

class SoSimple
{
public:							// 접근 제한 public
	static int simObjCnt;		// static 멤버변수 선언(클래스 멤버)
public:
	SoSimple()
	{
		simObjCnt++;
	}
};
int SoSimple::simObjCnt = 0;	// static 멤버변수의 초기화

int main(void)
{
	cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;	// 객체를 하나도 생성하지 않은 상태. public으로 선언된 static멤버는 어디서든 접근이 가능
	SoSimple sim1;
	SoSimple sim2;

	cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;	// static 멤버변수는 클래스변수이기 때문에 클래스 명으로 접근이 가능. static 선언을 하지 않을경우 클래스 명으로 접근이 불가능
	cout << sim1.simObjCnt << "번째 SoSimple 객체" << endl;			
	cout << sim2.simObjCnt << "번째 SoSimple 객체" << endl;
	return 0;
}