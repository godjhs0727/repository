#include <stdio.h>
#include <Windows.h>

int main()
{
	for(int i = 0;i <= 6; i += 3)
	{
		for (int j = 1; j <= 9; j++)
		{
			for (int k = 1; k <= 3; k++)
			{
				printf("%d * %d = %d\t", k + i, j, (k + i) * j);
			}
			printf("\n");
		}
		printf("\n");
	}

	for (int i = 1; i <= 9; i += 3)
	{
		for (int j = 1; j <= 9; j++)
		{
			for (int k = i; k < i + 3; k++)
			{
				printf("%d * %d = %d\t", k, j, k*j);
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("\n");

	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			for (int k = i; k <= 9; k += 3)
			{
				printf("%d * %d = %d\t", k, j, k*j);
			}
			printf("\n");
		}
		printf("\n");
	}

	system("pause");
	return 0;
}