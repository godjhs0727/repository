#include <stdio.h>
#include <Windows.h>

int main()
{
	//관계연산 -> 결과값 참(1, true) 혹은 거짓(0, false)
	//int a = 100;
	//int b = 20;

	//printf("a > b = %d\n", a > b); //크다 -> 1
	//printf("a < b = %d\n", a < b); //작다 -> 0
	//printf("a == b = %d\n", a == b); //같다 -> 0
	//printf("a == b = %d\n", a != b); //같지 않다 -> 0
	//printf("a >= b = %d\n", a >= b); //크거나 같다 -> 1
	//printf("a <= b = %d\n", a <= b); //작거나 같다 -> 0

	//삼항 연산자
	/*int input1, input2;

	printf("1st : ");
	scanf("%d", &input1);

	printf("2nd : ");
	scanf("%d", &input2);

	int max = (input1 > input2) ? (input1) : (input2);
	printf("둘 중 큰 수는 : %d 이다.\n", max);*/

	//bool
	bool bAlive = true;
	printf("(1)고통스럽게 죽여주는 약, (2)홍삼정\n");
	printf("어떤 약을 먹을까 ? :");

	int select;
	scanf("%d", &select);

	bAlive = (select == 1) ? false : true;

	(bAlive == true) ? printf("살았다\n") : printf("죽었다\n");


	system("pause");
	return 0;
}