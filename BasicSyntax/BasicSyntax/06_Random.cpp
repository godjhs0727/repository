#include <stdio.h>
#include <Windows.h>
#include <time.h>

#define SAY_HELLO printf("Hello~\n")
#define One 1
#define Two 2

int main()
{
	srand((UINT)time(NULL));

	while (true)//while : 반복문(괄호 안에 조건이 true 인 동안 계속 반복)
	{
		printf("%d\n", rand() % 20);
		Sleep(1000);
	};

	system("pause");
	return 0;
}