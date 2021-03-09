#include "stdafx.h"
typedef struct _Card
{
	bool open;
	string shape;
}Card;

int main()
{
	srand((UINT)time(NULL));
	string shape[16] = { "££","££","£¦","£¦","£ª","£ª","£À","£À","¡×","¡×","¡Ø","¡Ø","¡Ù","¡Ø","¡Ú","¡Ú" };
	

	for (int i = 0; i < 100; i++)
	{
		int r1 = rand() % 16;
		int r2 = rand() % 16;
		string temp = shape[r1];
		shape[r1] = shape[r2];
		shape[r2] = temp;
	}
	for (int i = 0; i < 16; i += 4)
	{
		for (int j = i; j < i + 4; j++)
		{
			cout << shape[j].c_str() << "\t";
		}
		cout << endl <<endl;
	}
	system("pause");
	return 0;
}