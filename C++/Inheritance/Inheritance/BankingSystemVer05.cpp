#include <iostream>
#include <cstring>
using namespace std;

const int NAME_LEN = 20;
enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

class Account
{
private:
	int accID;
	int balance;
	char* cusName;
public:
	Account(int ID, int money, const char* name);
	Account(const Account &ref);

	int GetID() const { return accID; }
	void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo() const;
	~Account();
};

Account::Account(int ID, int money, const char * name)
	:accID(ID),balance(money)
{
	cusName = new char[strlen(name) + 1];
	strcpy(cusName, name);
}

Account::Account(const Account & ref)
	:accID(ref.accID),balance(ref.balance)
{
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
}

void Account::Deposit(int money)
{
	balance += money;
}

int Account::Withdraw(int money)
{
	if(balance<0)
		return 0;
	balance -= money;
	return money;
}

void Account::ShowAccInfo() const
{
	cout << "계좌ID: " << accID << endl;
	cout << "잔액: " << balance << endl;
	cout << "이름: " << cusName << endl;
}

Account::~Account()
{
	delete[] cusName;
}

class AccountHandler
{
private:
	Account *accArr[100];
	int accNum;
public:
	AccountHandler();
	void ShowMenu() const;
	void MakeAccount();
	void DepositMoney();
	void WithdrawMoney();
	void ShowAllAccInfo() const;
	~AccountHandler();
};

AccountHandler::AccountHandler() :accNum(0)
{}

void AccountHandler::ShowMenu() const
{
	cout << "Menu" << endl;
	cout << "1.계좌개설" << endl;
	cout << "2.입금" << endl;
	cout << "3.출금" << endl;
	cout << "4.계좌정보확인" << endl;
	cout << "5.종료" << endl;
}

void AccountHandler::MakeAccount()
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "계좌개설" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "이름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << endl;

	accArr[accNum++] = new Account(id, balance, name);
}

void AccountHandler::DepositMoney()
{
	int money;
	int id;
	cout << "입금" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "입금액: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetID() == id)
		{
			accArr[i]->Deposit(money);
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID" << endl << endl;

}

void AccountHandler::WithdrawMoney()
{
	int money;
	int id;
	cout << "출금" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "출금액: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetID() == id)
		{
			if (accArr[i]->Withdraw(money) == 0)
			{
				cout << "잔액부족" << endl;
				return;
			}
			cout << "출금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID" << endl << endl;
}

void AccountHandler::ShowAllAccInfo() const
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
	{
		delete accArr[i];
	}
}

int main()
{
	AccountHandler manager;
	int choice;

	while (true)
	{
		manager.ShowMenu();
		cout << "선택: "; cin >> choice;
		cout << endl;

		switch (choice)
		{	
		case MAKE:
			manager.MakeAccount();
			break;
		case DEPOSIT:
			manager.DepositMoney();
			break;
		case WITHDRAW:
			manager.WithdrawMoney();
			break;
		case INQUIRE:
			manager.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}
	return 0;
}