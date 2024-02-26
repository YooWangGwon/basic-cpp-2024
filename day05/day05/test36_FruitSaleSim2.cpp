// file : test36_FruitSaleSim2.cpp
// date : 240226
// desc : 생성자 적용(p.173~176)

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
		int num = money / APPLE_PRICE; // 판매한 개수
		numOfApples -= num;            // 남은 사과 개수 : numOfApples = numOfApples - num(복합대입연산자:+=,-=,*=,/=,%=)
		myMoney += money;              // 사과 판매로 생긴 누적 수익 : myMoney = myMoney + money
		return num;
	}
	void ShowSaleseResult()
	{
		cout << "남은 사과: " << numOfApples << endl;
		cout << "판매 수익: " << myMoney << endl << endl;
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
		cout << "현재 잔액: " << myMoney << endl;
		cout << "사과 개수: " << numOfApples << endl << endl;
	}
};

int main(void)
{
	FruitSeller seller(1000, 20, 0); //(사과 개당 가격, 보유 사과 개수, 현재 수익)
	FruitBuyer buyer(5000);
	buyer.BuyApples(seller, 2000);

	cout << "과일 판매자의 현황" << endl;
	seller.ShowSaleseResult();
	cout << "과일 구매자의 현황" << endl;
	buyer.ShowBuyResult();
	return 0;
}