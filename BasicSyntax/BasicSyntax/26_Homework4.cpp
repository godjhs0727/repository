#include"stdafx.h"
//bool ���� �ְ� �Ұ��� Ʈ��� �ڿ� ������ Ư�����ڰ� �������� ������ ���ڰ� ���̰�

struct Card
{
	string symbol; //��� ������� ������Ÿ��
	bool bShowSymbol; //�����ؼ� �̰� Ʈ��� Ư�����ڰ� ���̰� �����̸� ����
};
void Shuffle(Card** card);
void RenderCard(Card** card);
void FirstShow(Card** card);
void Play(Card** card, Card** selected);

int main()
{
	Card* card[16]; //���ӿ뿡 ���� ī�尡 16���̴�. �����ͷ� �θ� ���δ� �ּҰ� ���ü� �ְ� 4����Ʈ �ϳ��� ���̶� ��Ʈ���� �ٴ´�.
	Card* selected[2]; //�����ϴ� ī��
	selected[0] = selected[1] = NULL; //ó���� �ƹ��͵� ���ٶ�� �ʱ�ȭ
	
	//int a; //17���� Ŭ���ϸ� ������ �̰� �극��ũ����Ʈ
	//a = 10;
	//
	//int arr[3] = { 1,2,3 };
	//for (int i = 0; i < 3; i++)
	//	arr[i] = i;

	Shuffle(card);
	FirstShow(card);

	while (true)
	{
		RenderCard(card);
		Play(card, selected);
	}

	//�ߴ���(Break Point)

	system("pause");
	return 0;
}

void Shuffle(Card ** card)
{
	//ī���ʱ�ȭ
	for (int i = 0; i < 2; i++) //�ΰ��� �Ȱ����ɷ� �ι�
	{
		card[i * 8 + 0] = new Card{ "��",true };
		card[i * 8 + 1] = new Card{ "��",true };
		card[i * 8 + 2] = new Card{ "��",true };
		card[i * 8 + 3] = new Card{ "��",true };
		card[i * 8 + 4] = new Card{ "��",true };
		card[i * 8 + 5] = new Card{ "��",true };
		card[i * 8 + 6] = new Card{ "��",true };
		card[i * 8 + 7] = new Card{ "��",true };

	}
	//����
	srand((UINT)time(NULL));
	for (UINT i = 0; i < 100; i++)
	{
		int r1 = rand() % 16;
		int r2 = rand() % 16;

		Card* temp = card[r1]; //Card card �̰� ������ Ÿ��
		card[r1] = card[r2];
		card[r2] = temp;
		//swap(card[r1],card[r2]) �̷��� ���ҽ��ѵ� �ȴ�.
	}
}

void RenderCard(Card ** card)
{
	system("cls");

	for (int i = 0; i < 16; i++)
	{
		if (card[i]->bShowSymbol == true)
		{
			cout << card[i]->symbol.c_str() << "\t";
		}
		else
			cout << i << "\t";

		if (i % 4 == 3)
			cout << endl << endl;
	}
	Sleep(500);
}

void FirstShow(Card ** card)
{
	for (UINT i = 0; i < 16; i++)
	{
		RenderCard(card);
		card[i]->bShowSymbol = false;
		Sleep(25);
	}
	system("cls");

}

void Play(Card ** card, Card ** selected)
{
	UINT input;
	cout << "�Է� : ";
	cin >> input;

	if (input > 15)
	{
		cout << "ī���� �ε��� ������ ���" << endl;
		return; //���İ��� cls�� ����
	}

	if (card[input]->bShowSymbol == false)
	{
		card[input]->bShowSymbol = true;

		if (selected[0] == NULL)
			selected[0] = card[input];
		else
			selected[1] = card[input];
	}
	if (selected[0] != NULL && selected[1] != NULL)
	{
		RenderCard(card);

		if (selected[0]->symbol != selected[1]->symbol)
		{
			selected[0]->bShowSymbol = false;
			selected[1]->bShowSymbol = false;

		}
		selected[0] = selected[1] = NULL;
	}
}

//Ŭ���� ����