#include <stdio.h>
#include <Windows.h>

int main()
{

	//if 예제
	int input = 1;
	
	while (true)
	{
		printf("숫자를 하나 입력하세요 : ");
		scanf("%d", &input);

		/*if (input == 7)
		{
			printf("나는 7이다.\n");
		}
		else if(input > 0)
		{
			printf("나는 7이 아니면서, 양수값이다.\n");
		}
		else if (input < 0)
		{
			printf("나는 7이 아니면서, 음수값이다.\n");
		}
		else
		{
			printf("나는 7이 아니다\n");
		}*/

		//조건 범위를 설정할때 주의사항
		/*if (input > 0)
		{
			printf("+\n");
		}
		else if (input == 7)
		{
			printf("7\n");
		}*/

		if (input > 0)
		{
			if (input == 1)
			{
				printf("1이 입력됨\n");
			}
			else if (input == 2)
			{
				printf("2가 입력됨\n");
			}
			else
			{
				printf("1과 2가 아닌 양수값이 입력됨");
			}

		} //if(input > 0)
		else
		{
			printf("양수가 아닌 값이 입력됨\n");
		}

		
	} //while
	

	system("pause");
	return 0;
}