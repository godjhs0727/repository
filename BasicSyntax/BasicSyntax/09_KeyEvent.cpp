#include <stdio.h>
#include <Windows.h>

int main()
{
	while (true)
	{
		system("cls");

		if (GetAsyncKeyState('A'))
		{
			printf("A키가 눌림\n");
		}
		
		else if (GetAsyncKeyState('D'))
		{
			printf("D키가 눌림\n");
		}

		else if (GetAsyncKeyState('W'))
		{
			printf("W키가 눌림\n");
		}

		else if (GetAsyncKeyState('S'))
		{
			printf("S키가 눌림\n");
		}

		
	}

	system("pause");
	return 0;
}