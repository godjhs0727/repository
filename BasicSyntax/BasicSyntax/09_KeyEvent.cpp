#include <stdio.h>
#include <Windows.h>

int main()
{
	while (true)
	{
		system("cls");

		if (GetAsyncKeyState('A'))
		{
			printf("AŰ�� ����\n");
		}
		
		else if (GetAsyncKeyState('D'))
		{
			printf("DŰ�� ����\n");
		}

		else if (GetAsyncKeyState('W'))
		{
			printf("WŰ�� ����\n");
		}

		else if (GetAsyncKeyState('S'))
		{
			printf("SŰ�� ����\n");
		}

		
	}

	system("pause");
	return 0;
}