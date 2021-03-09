#include"stdafx.h"
//bool 값을 주고 불값이 트루면 뒤에 숨겨진 특수문자가 보여지고 풜스면 숫자가 보이게

struct Card
{
	string symbol; //모양 만들어줄 데이터타입
	bool bShowSymbol; //오픈해서 이게 트루면 특수문자가 보이고 거짓이면 숫자
};
void Shuffle(Card** card);
void RenderCard(Card** card);
void FirstShow(Card** card);
void Play(Card** card, Card** selected);

int main()
{
	Card* card[16]; //게임용에 쓰일 카드가 16개이다. 포인터로 두면 전부다 주소가 들어올수 있고 4바이트 하나당 불이랑 스트링이 붙는다.
	Card* selected[2]; //선택하는 카드
	selected[0] = selected[1] = NULL; //처음에 아무것도 없다라고 초기화
	
	//int a; //17옆에 클릭하면 빨간점 이게 브레이크포인트
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

	//중단점(Break Point)

	system("pause");
	return 0;
}

void Shuffle(Card ** card)
{
	//카드초기화
	for (int i = 0; i < 2; i++) //두개씩 똑같은걸로 두번
	{
		card[i * 8 + 0] = new Card{ "＃",true };
		card[i * 8 + 1] = new Card{ "＆",true };
		card[i * 8 + 2] = new Card{ "＊",true };
		card[i * 8 + 3] = new Card{ "＠",true };
		card[i * 8 + 4] = new Card{ "§",true };
		card[i * 8 + 5] = new Card{ "※",true };
		card[i * 8 + 6] = new Card{ "☆",true };
		card[i * 8 + 7] = new Card{ "★",true };

	}
	//셔플
	srand((UINT)time(NULL));
	for (UINT i = 0; i < 100; i++)
	{
		int r1 = rand() % 16;
		int r2 = rand() % 16;

		Card* temp = card[r1]; //Card card 이게 포인터 타입
		card[r1] = card[r2];
		card[r2] = temp;
		//swap(card[r1],card[r2]) 이렇게 스왑시켜도 된다.
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
	cout << "입력 : ";
	cin >> input;

	if (input > 15)
	{
		cout << "카드의 인덱스 범위를 벗어남" << endl;
		return; //순식간에 cls로 빠짐
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

//클래스 예습