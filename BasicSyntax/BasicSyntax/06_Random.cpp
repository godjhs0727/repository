#include <stdio.h>
#include <Windows.h>
#include <time.h>

#define SAY_HELLO printf("Hello~\n")
#define One 1
#define Two 2

int main()
{
	srand((UINT)time(NULL));

	while (true)//while : �ݺ���(��ȣ �ȿ� ������ true �� ���� ��� �ݺ�)
	{
		printf("%d\n", rand() % 20);
		Sleep(1000);
	};

	system("pause");
	return 0;
}