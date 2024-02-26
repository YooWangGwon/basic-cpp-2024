// file : test28_object.cpp
// date : 240226
// desc : Ŭ���� ����� �ΰ��� ��ü ���� ���(p.142~144) 

# include <iostream>
using namespace std; // cout�� endl�� ���ϰ� ����ϱ� ���� ���Ӱ���

class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;
public:
	void InitMembers(int price, int num, int money) // ������ : ��ü�� �����ϰ� �ʱ�ȭ��.
	{
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}
	int SaleApples(int money)
	{
		int num = money / APPLE_PRICE; // �Ǹ��� ����
		numOfApples -= num;            // ���� ��� ���� : numOfApples = numOfApples - num(���մ��Կ�����:+=,-=,*=,/=,%=)
		myMoney += money;              // ��� �Ǹŷ� ���� ���� ���� : myMoney = myMoney + money
		return num;
	}
	void ShowSaleseResult()
	{
		cout << "���� ���: " << numOfApples << endl;
		cout << "�Ǹ� ����: " << myMoney << endl << endl;
	}
};

class FruitBuyer
{
	int myMoney;
	int numOfApples;

public:
	void InitMembers(int money)
	{
		myMoney = money;
		numOfApples = 0;
	}
	void BuyApples(FruitSeller &refseller, int money) // FruitSeller�� �����ϰ� �ִ� refseller(�Լ� �������� ��� ����)
	{
		numOfApples += refseller.SaleApples(money); // FruitSeller�� �ִ� �Լ��� ������
		myMoney -= money;
	}
	void ShowBuyResult()
	{
		cout << "���� �ܾ�: " << myMoney << endl;
		cout << "��� ����: " << numOfApples << endl << endl;
	}
};

int main(void)
{
	FruitSeller seller; // ���ÿ��� �޸𸮸� �Ҵ����
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000); // refseller�� ������ Ŭ���� FruitSeller�� ����Ű�� ������ ��밡���� ������ �ٸ���.(refseller�� �Լ��� ���� �������� ��밡��)

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.ShowSaleseResult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer.ShowBuyResult();
	return 0;
}