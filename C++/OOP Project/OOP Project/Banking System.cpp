/*
���� ���������� ���� ��
---Menu---
1.���°���
2.�Ա�
3.���
4.�������� ��ü ���
5.���α׷� ����
����:1

[���°���]
����ID:115
�̸�:�̿켮
�Աݾ�:15000

---Menu---
1.���°���
2.�Ա�
3.���
4.�������� ��ü ���
5.���α׷� ����
����:2

[�Ա�]
����ID:115
�Աݾ�:70
�ԱݿϷ�

---Menu---
1.���°���
2.�Ա�
3.���
4.�������� ��ü ���
5.���α׷� ����
����:4

[�������� ��ü ���]
����ID:115
�̸�:�̿켮
�ܾ�:15070

*/

#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

void ShowMenu(); //�޴� ���
void MakeAccount();//���� ����
void DepositMoney();//�Ա�
void WithdrawMoney();//���
void ShowAllAccInfo();//�ܾ� ��ȸ
enum {Make=1, Deposit, Withdraw, Show, Exit}; //���� ��ȣ

typedef struct
{
	int accID; //���¹�ȣ
	int balance; //�ܾ�
	char cusNAME[NAME_LEN]; //���� �̸�
} Account; //����ü �̸� ����

Account accArr[100]; //Account ������ ���� �迭 100�� ���� ����
int accNum = 0; //����� Account ��

int main()
{
	int choice;

	while (true)
	{
		ShowMenu();
		cout << "����:";
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
	cout << "1.���°���\n2.�Ա�\n3.���\n4.�������� ��ü ���" << endl;
	cout << "5.���α׷� ����" << endl;
}

void MakeAccount()
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[���°���]" << endl;
	cout << "����ID:"; cin >> id;
	cout << "�̸�:"; cin >> name;
	cout << "�Աݾ�:"; cin >> balance;
	cout << endl;

	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	strcpy(accArr[accNum].cusNAME, name);
	accNum++; //���� ��������� ���°�

}

void DepositMoney()
{
	int money;
	int id;
	cout << "�Ա�" << endl;
	cout << "����ID:" ; cin >> id;
	cout << "�Աݾ�:"; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			accArr[i].balance += money;
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;

}

void WithdrawMoney()
{
	int money;
	int id;

	cout << "���" << endl;
	cout << "����ID:"; cin >> id;
	cout << "��ݾ�:"; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			if (accArr[i].balance < money)
			{
				cout << "�ܾ׺���" << endl;
				return;
			}
			accArr[i].balance -= money;
			cout << "��ݿϷ�" << endl << endl;
			return;
		}

	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
	
}

void ShowAllAccInfo()
{
	for (int i = 0; i < accNum; i++)
	{
		cout << "���� ID: " << accArr[i].accID << endl;
		cout << "��   ��: " << accArr[i].cusNAME << endl;
		cout << "��   ��: " << accArr[i].balance << endl;
	}
	cout << endl;
}