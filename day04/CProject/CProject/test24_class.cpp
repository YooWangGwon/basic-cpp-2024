// file : test24_class.cpp
// date : 240223
// desc : 클래스  - 접근제어(p.121~126)

#include <iostream>
#include <cstring>
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

class Car
{
// 멤버변수, 필드, 속성(Attribute)
private: // 클래스 내(클래스 내에 정의된 함수)에서만 접근허용
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;

// 멤버함수, 메서드, 기능
public: // 어디서든 접근허용
	void InitMembers(const char* ID, int fuel);
	void ShowCarState();
	void Accel();
	void Break();
};

// 함수 정의
void Car::InitMembers(const char* ID, int fuel) //필드의 초기화 담당 메서드
{
	strcpy(gamerID, ID); // 전달된 ID의 문자열을 복사해서 gamerID에 저장, 복사하는 값이 변경되지 않도록 const를 사용
	fuelGauge = fuel;
	curSpeed = 0;
}

void Car::ShowCarState() // 멤버 함수에 대한 정의는 밖에 (C++에서만 지원)
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
	Car run99; // class Car 타입의 객체 run99 생성 -> 실질적으로 클래스를 사용할 수 있는 객체가 생성됨
	run99.InitMembers("run99", 100); // run99 객체의 InitMembers() 메서드 호출
	run99.Accel();
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();
	return 0;
}