//���� FruitSaleSim1.cpp���� ������ �� Ŭ������ ��������� private���� ������ �Ǿ��ִ�.
//�׷��� ���� ������ ������ �� �ִ� ��ġ�� �ƹ��͵� �Ǿ����� �ʴ�.
//-����� ���Ÿ� �������� 0���� ���� ���� ������ �� ����.
//���� ��������� �׻� ������ų �� �ֵ��� ������ �����ϰ�, ������ �������� ���� �� �ֵ��� �Ϻ�
//�Լ��� const�� �����غ���.
#include <iostream>
using namespace std;

class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:
	void InitMembers(int price, int num, int money)
	{
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}
	int SaleApples(int money)
	{
		if (money < 0)
		{
			cout << "�߸��� ������ ���޵Ǿ� �ǸŸ� ����մϴ�." << endl;
			return 0; //int �Լ��� return 0; default ���ش�.
		}
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}
	void ShowSaleResult() const //�����ֱ⸸ �ϴ°Ŷ� ���ȭ ����
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
	void InitMembers(int money)
	{
		myMoney = money;
		numOfApples = 0;
	}
	void BuyApples(FruitSeller &seller, int money)
	{
		if (money < 0)
		{
			cout << "�߸��� ������ ���޵Ǿ� ���Ÿ� ����մϴ�." << endl;
			return; //void�Լ��� return; �ƹ��͵� ����
		}
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}
	void ShowBuyResult() const //�����ֱ⸸ �ϴ°Ŷ� ���ȭ ����
	{
		cout << "���� �ܾ�: " << myMoney << endl;
		cout << "��� ����: " << numOfApples << endl << endl;
	}
};

int main()
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(2000);
	buyer.BuyApples(seller, 1000);

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.ShowSaleResult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer.ShowBuyResult();

	return 0;
}