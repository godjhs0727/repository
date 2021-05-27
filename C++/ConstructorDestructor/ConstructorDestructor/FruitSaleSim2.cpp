//�����ڰ� �������� �˾�����, ���� �ߴ� fruitSaleSim1.cpp�� �����ڸ� ��������

#include <iostream>
using namespace std;

class FruitSeller
{
private:
	const int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:

	FruitSeller(int price, int num, int money) //�����ڸ� �̿��ؼ� Member Initializer�� �����ϴ�.
		:APPLE_PRICE(price) //�̴ϼȶ������� �̿��ϸ� ����� ���ÿ� �ְ��ϰ� �̷����� ���·� ���̳ʸ� �ڵ尡 �����ȴ�
		//const��������� �̴ϼȶ������� �̿��ϸ� �ʱ�ȭ�� �����ϴ�!
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
		cout << "���� ���: " << numOfApples << endl;
		cout << "�Ǹ� ����: " << myMoney << endl << endl;
	}
};

class FruitBuyer
{
private:
	int myMoney;
	int numOfApples;

public:
	FruitBuyer(int money)
	/*	:myMoney(money), numOfApples(0)*/ //�Ʒ� �ڵ��� 
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
		cout << "���� �ܾ�: " << myMoney << endl;
		cout << "��� ����: " << numOfApples << endl << endl;
	}
};

int main()
{
	FruitSeller seller(1000, 20, 0);
	FruitBuyer buyer(2000);	
	buyer.BuyApples(seller, 1000);

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.ShowSaleResult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer.ShowBuyResult();

	return 0;
}