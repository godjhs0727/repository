//생성자가 무엇인지 알았으니, 전에 했던 fruitSaleSim1.cpp에 생성자를 적용하자

#include <iostream>
using namespace std;

class FruitSeller
{
private:
	const int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:

	FruitSeller(int price, int num, int money) //생성자를 이용해서 Member Initializer가 가능하다.
		:APPLE_PRICE(price) //이니셜라이저를 이용하면 선언과 동시에 최고하가 이뤄지는 형태로 바이너리 코드가 생성된다
		//const멤버변수도 이니셜라이저를 이용하면 초기화가 가능하다!
	{
		
		numOfApples = num;
		myMoney = money;
	}
	int SaleApples(int money)
	{
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}
	void ShowSaleResult() const
	{
		cout << "남은 사과: " << numOfApples << endl;
		cout << "판매 수익: " << myMoney << endl << endl;
	}
};

class FruitBuyer
{
private:
	int myMoney;
	int numOfApples;

public:
	FruitBuyer(int money)
	/*	:myMoney(money), numOfApples(0)*/ //아래 코드대신 
	{
		myMoney = money;
		numOfApples = 0;
	}
	void BuyApples(FruitSeller &seller, int money)
	{
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}
	void ShowBuyResult() const
	{
		cout << "현재 잔액: " << myMoney << endl;
		cout << "사과 개수: " << numOfApples << endl << endl;
	}
};

int main()
{
	FruitSeller seller(1000, 20, 0);
	FruitBuyer buyer(2000);	
	buyer.BuyApples(seller, 1000);

	cout << "과일 판매자의 현황" << endl;
	seller.ShowSaleResult();
	cout << "과일 구매자의 현황" << endl;
	buyer.ShowBuyResult();

	return 0;
}