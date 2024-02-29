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
			cout << endl << "������ �ʿ��մϴ�" << endl;
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
		cout << "���� �Ϸ�" << endl;
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
			cout << endl << "������ �����մϴ�" << endl;
		}
		else
		{
			cout << "SNAP!" << "  ";
			handcuffs--;
		}

	}
	void state()
	{
		cout << "��ź ��: " << Remain() << endl;
		cout << "�ܿ� ���� ��: " << handcuffs << endl;
	}
	void SupplyHandcuff()
	{
		handcuffs += 3;
		cout << "���� ���� �Ϸ�" << endl;
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