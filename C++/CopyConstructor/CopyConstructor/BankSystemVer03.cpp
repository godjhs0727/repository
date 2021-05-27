#include <iostream>
#include <cstring>
using namespace std;

class Account
{
private:
	int accID;
	int balance;
	char * cusName;
public:
	Account(int ID, int money, const char* name) :accID(ID), balance(money)
	{
		cusName = new char[strlen(name) + 1];
		strcpy(cusName, name);
	}
	Account(const Account& ref) :accID(ref.accID), balance(ref.balance) //º¹»ç»ý¼ºÀÚ
	{
		cusName = new char[strlen(ref.cusName) + 1];
		strcpy(cusName, ref.cusName);
	}
	int GetAccID() { return accID; }

	void Deposit(int money)
	{
		balance += money;
	}
	
	int Withdraw(int money)
	{
		if (balance < money)
			return 0;
		balance -= money;
		return money;
	}

	void ShowAccInfo()
	{
		cout << "°èÁÂID: " << accID << endl;
		cout << "ÀÜ¾×: " << balance << endl;
		cout << "°í°´ÀÌ¸§: " << cusName << endl;
	}
	~Account()
	{
		delete[] cusName;
	}
};