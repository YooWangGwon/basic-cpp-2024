// file : test28_object.cpp
// date : 240226
// desc : 클래스 기반의 두가지 객체 생성 방법(p.142~144) 

# include <iostream>
using namespace std; // cout과 endl을 편리하게 사용하기 위한 네임공간

class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;
public:
	void InitMembers(int price, int num, int money) // 생성자 : 객체를 생성하고 초기화함.
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
	void InitMembers(int money)
	{
		myMoney = money;
		numOfApples = 0;
	}
	void BuyApples(FruitSeller &refseller, int money) // FruitSeller를 참조하고 있는 refseller(함수 내에서만 사용 가능)
	{
		numOfApples += refseller.SaleApples(money); // FruitSeller에 있는 함수를 가져옴
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
	FruitSeller seller; // 스택에서 메모리를 할당받음
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000); // refseller와 동일한 클래스 FruitSeller를 가리키고 있지만 사용가능한 범위를 다르다.(refseller는 함수의 정의 내에서만 사용가능)

	cout << "과일 판매자의 현황" << endl;
	seller.ShowSaleseResult();
	cout << "과일 구매자의 현황" << endl;
	buyer.ShowBuyResult();
	return 0;
}