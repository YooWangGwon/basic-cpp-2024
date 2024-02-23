// file : test20_enum
// date : 20240223
// desc : ����ü �ȿ� enum ��� ����(p.115~118)

#include <iostream>
using namespace std;

namespace CAR_CONST
{
	enum // enum : ������(enumerated type)�̶���� �θ��� ���� ������ ������� ������ �ǹ�  -> enum Ű���� : ������ �ڷḦ ���鶧 ���
	{
		ID_LEN = 20, // ������ �ڷḦ ���鶧�� ������ ��� �빮�ڷ� -> ���ȭ
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP =10
	};
}

struct Car // ������� : gamerID, fuelGauge, curspeed, ��� �Լ� : ShowCarState(), Accel(), Break()
{
	char gamerID[CAR_CONST::ID_LEN]; // gameID��� �̸��� char Ÿ�� �迭�� CAR_CONST::ID_LEN��ŭ ���� (�迭��['�迭�� ���� ����']) // CAR_CONST::ID_LEN -> CAR_CONST�� ���ϴ� ID_LEN
	int fuelGauge;
	int curSpeed;

	void ShowCarState()
	{
		cout << "������:ID " << gamerID << endl;
		cout << "���ᷮ : " << fuelGauge << "%" << endl;
		cout << "���� �ӵ� : " << curSpeed << "km/s" << endl << endl;
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
	Car run99 = { "run99",100,0 }; // ���ÿ������� �������
	run99.Accel(); // Car ����ü�� ����Լ� Accel ���� -> 98, 10
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

// ��ü : new��� Ű���带 ���� ��(heap) �������� ���������.