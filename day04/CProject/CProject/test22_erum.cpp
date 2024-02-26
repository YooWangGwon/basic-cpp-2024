// file : test22_enum
// date : 20240223
// desc : 구조체 안에 enum 상수 선언(p.115~118)

#include <iostream>
using namespace std;

namespace CAR_CONST
{
	enum // enum : 열거형(enumerated type)이라고도 부르며 서로 연관된 상수들의 집합을 의미  -> enum 키워드 : 열거형 자료를 만들때 사용
	{
		ID_LEN = 20, // 열거형 자료를 만들때는 변수를 모두 대문자로 -> 상수화
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP =10
	};
}

struct Car // 멤버변수 : gamerID, fuelGauge, curspeed, 멤버 함수 : ShowCarState(), Accel(), Break()
{
	char gamerID[CAR_CONST::ID_LEN]; // gameID라는 이름의 char 타입 배열을 CAR_CONST::ID_LEN만큼 생성 (배열명['배열의 방의 개수']) // CAR_CONST::ID_LEN -> CAR_CONST에 속하는 ID_LEN
	int fuelGauge;
	int curSpeed;

	void ShowCarState()
	{
		cout << "소유자:ID " << gamerID << endl;
		cout << "연료량 : " << fuelGauge << "%" << endl;
		cout << "현재 속도 : " << curSpeed << "km/s" << endl << endl;
	}
	void Accel() 
	{
		if (fuelGauge <= 0)
			return;
		else
			fuelGauge -= CAR_CONST::FUEL_STEP;

		if ((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD)
		{
			curSpeed = CAR_CONST::MAX_SPD;
			return;
		}

		curSpeed += CAR_CONST::ACC_STEP;
	}
	void Break()
	{
		if (curSpeed < CAR_CONST::BRK_STEP)
		{
			curSpeed = 0;
			return;
		}

		curSpeed -= CAR_CONST::BRK_STEP;
	}
};

int main(void)
{
	Car run99 = { "run99",100,0 }; // 스택영역에서 만들어짐
	run99.Accel(); // Car 구조체의 멤버함수 Accel 실행 -> 98, 10
	run99.Accel(); // 96, 20
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();

	Car sped77 = { "sped77", 100, 0 };
	sped77.Accel();
	sped77.Break();
	sped77.ShowCarState();
	return 0;
}

// 객체 : new라는 키워드를 쓰면 힙(heap) 영역에서 만들어진다.
