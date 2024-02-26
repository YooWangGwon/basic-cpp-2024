// file : test36_FruitSaleSim2.cpp
// date : 240226
// desc : ������ ����(p.173~176)

# include <iostream>
using namespace std; 

class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;
public:
	FruitSeller(int price, int num, int money) 
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
	FruitBuyer(int money)
	{
		myMoney = money;
		numOfApples = 0;
	}
	void BuyApples(FruitSeller& refseller, int money)
	{
		numOfApples += refseller.SaleApples(money); 
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
	FruitSeller seller(1000, 20, 0); //(��� ���� ����, ���� ��� ����, ���� ����)
	FruitBuyer buyer(5000);
	buyer.BuyApples(seller, 2000);

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.ShowSaleseResult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer.ShowBuyResult();
	return 0;
}