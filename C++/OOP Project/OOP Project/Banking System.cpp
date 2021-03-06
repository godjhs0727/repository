/*
계좌 개설과정의 실행 예
---Menu---
1.계좌개설
2.입금
3.출금
4.계좌정보 전체 출력
5.프로그램 종료
선택:1

[계좌개설]
계좌ID:115
이름:이우석
입금액:15000

---Menu---
1.계좌개설
2.입금
3.출금
4.계좌정보 전체 출력
5.프로그램 종료
선택:2

[입금]
계좌ID:115
입금액:70
입금완료

---Menu---
1.계좌개설
2.입금
3.출금
4.계좌정보 전체 출력
5.프로그램 종료
선택:4

[계좌정보 전체 출력]
계좌ID:115
이름:이우석
잔액:15070

*/

#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

void ShowMenu(); //메뉴 출력
void MakeAccount();//계좌 개설
void DepositMoney();//입금
void WithdrawMoney();//출금
void ShowAllAccInfo();//잔액 조회
enum {Make=1, Deposit, Withdraw, Show, Exit}; //선택 번호

typedef struct
{
	int accID; //계좌번호
	int balance; //잔액
	char cusNAME[NAME_LEN]; //고객 이름
} Account; //구조체 이름 지정

Account accArr[100]; //Account 저장을 위한 배열 100명 저장 가능
int accNum = 0; //저장된 Account 수

int main()
{
	int choice;

	while (true)
	{
		ShowMenu();
		cout << "선택:";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case Make:
			MakeAccount();
			break;
		case Deposit:
			DepositMoney();
			break;
		case Withdraw:
			WithdrawMoney();
			break;
		case Show:
			ShowAllAccInfo();
			break;
		case Exit:
			return 0;
		default:
			cout << "Illegal Selection" << endl;
		}
	}

	return 0;
}

void ShowMenu()
{
	cout << "---Menu---" << endl;
	cout << "1.계좌개설\n2.입금\n3.출금\n4.계좌정보 전체 출력" << endl;
	cout << "5.프로그램 종료" << endl;
}

void MakeAccount()
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID:"; cin >> id;
	cout << "이름:"; cin >> name;
	cout << "입금액:"; cin >> balance;
	cout << endl;

	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	strcpy(accArr[accNum].cusNAME, name);
	accNum++; //은행 통산정보에 들어가는것

}

void DepositMoney()
{
	int money;
	int id;
	cout << "입금" << endl;
	cout << "계좌ID:" ; cin >> id;
	cout << "입금액:"; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			accArr[i].balance += money;
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;

}

void WithdrawMoney()
{
	int money;
	int id;

	cout << "출금" << endl;
	cout << "계좌ID:"; cin >> id;
	cout << "출금액:"; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			if (accArr[i].balance < money)
			{
				cout << "잔액부족" << endl;
				return;
			}
			accArr[i].balance -= money;
			cout << "출금완료" << endl << endl;
			return;
		}

	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
	
}

void ShowAllAccInfo()
{
	for (int i = 0; i < accNum; i++)
	{
		cout << "계좌 ID: " << accArr[i].accID << endl;
		cout << "이   름: " << accArr[i].cusNAME << endl;
		cout << "잔   액: " << accArr[i].balance << endl;
	}
	cout << endl;
}
