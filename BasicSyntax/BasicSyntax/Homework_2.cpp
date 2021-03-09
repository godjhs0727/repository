#include <stdio.h>
#include <Windows.h>

int main()
{
	printf("----------<3Сп for>--------------------------------\n");
	for (int i = 1; i <= 9; i += 3)
	{
		for (int j = 1; j <= 9; j++)
		{

			for (int k = i; k < 3 + i; k++)
			{
				printf("%d * %d = %d\t", k, j, k * j);
			}
			printf("\n");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}