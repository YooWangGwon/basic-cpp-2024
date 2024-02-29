# include <iostream>
# include <cstring>
using namespace std;

class Gun
{
private:
	int bullet;
public:
	Gun(int bnum) : bullet(bnum)
	{ }
	void Shot()
	{
		if (bullet < 1)
		{
			cout << endl << "장전이 필요합니다" << endl;
		}
		else
		{
			cout << "BBang!" << "  ";
			bullet--;
		}
	}
	void Reloading()
	{
		bullet += 5;
		cout << "장전 완료" << endl;
	}
	int Remain()
	{
		return bullet;
	}
};

class Police : public Gun
{
private:
	int handcuffs;
public:
	Police(int bnum, int bcuff)
		:Gun(bnum), handcuffs(bcuff)
	{ }
	void PutHandcuff()
	{
		if (handcuffs < 1)
		{
			cout << endl << "수갑이 부족합니다" << endl;
		}
		else
		{
			cout << "SNAP!" << "  ";
			handcuffs--;
		}

	}
	void state()
	{
		cout << "잔탄 수: " << Remain() << endl;
		cout << "잔여 수갑 수: " << handcuffs << endl;
	}
	void SupplyHandcuff()
	{
		handcuffs += 3;
		cout << "수갑 보충 완료" << endl;
	}
};

int main(void)
{
	Police pman(5, 3);
	pman.state();
	for (int i = 0; i < 6; i++)
		pman.Shot();
	for (int i = 0; i < 4; i++)
		pman.PutHandcuff();
	pman.state();
	pman.Reloading();
	pman.state();
	pman.SupplyHandcuff();
	pman.state();

	return 0;
}