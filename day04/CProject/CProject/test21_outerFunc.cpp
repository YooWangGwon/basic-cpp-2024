// file : test21_OuterFunc.cpp
// date : 240223
// desc : 함수의 정의를 밖으로 빼는 법(p.118~121)


#include <iostream>
using namespace std;

namespace CAR_CONST
{
	enum
	{
		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP = 10
	};
}

struct Car
{
	//======멤버변수=======
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;

	//======멤버함수=======
	void ShowCarState(); // 구조체에 멤버 함수에 대한 선언만	
	void Accel();
	void Break();
};
void Car:: ShowCarState() // 멤버 함수에 대한 정의는 밖에 (C++에서만 지원)
{
	cout << "소유자:ID " << gamerID << endl;
	cout << "연료량 : " << fuelGauge << "%" << endl;
	cout << "현재 속도 : " << curSpeed << "km/s" << endl << endl;
}

void Car::Accel()
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

void Car::Break()
{
	if (curSpeed < CAR_CONST::BRK_STEP)
	{
		curSpeed = 0;
		return;
	}

	curSpeed -= CAR_CONST::BRK_STEP;
}

int main(void)
{
	Car run99 = { "run99",100,0 }; 
	run99.Accel(); 
	run99.Accel();
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