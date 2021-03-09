#include <stdio.h>
#include <Windows.h>

int main()
{
	int result;
	int a = 10, b = 3;
	
	//산술 연산(이항연산자)
	result = a + b;
	printf("덧셈 결과 : %d\n", result);

	result = a - b;
	printf("뺄셈 결과 : %d\n", result);

	result = a * b;
	printf("곱셈 결과 : %d\n", result);

	result = a / b;
	printf("나눗셈 결과 : %d\n", result);

	result = a % b;
	printf("나머지 결과 : %d\n", result);

	//Cast
	float result2;
	result2 = (float)a / (float)b; //명시적 cast
	printf("나눗셈 결과2 : %f\n", result2);

	double c = 3;
	printf("결과 : %f\n", a / c); //암시적 cast
	
	result2 = (a + 1) * (b * 2); //-> 실행 결과? -> 16
	printf("결과 : %f\n", result2);
	
	//단항연산(증감연산)
	printf("-------------------------------\n");
	int num1, num2, num3, num4, num5;
	num1 = num2 = num3 = num4 = num5 = 1;
	
	num1 += 1; //num1 = num1 + 1;
	printf("num1 + 1 = %d\n", num1);

	//++, --
	//++num3; // + 1
	//printf("Prefix : %d\n", num3);

	//num4++; //num4 = num4 -> 한줄 내려와야 + 1
	//printf("Postfix : %d\n", num4);

	printf("Prefix : %d\n", ++num3);
	printf("Postfix : %d\n", num4++);
	printf("Num4 : %d\n", num4);


	printf("----------------------------------\n");
	int number = 10;
	printf("%d\n", number++); //-> 10
	printf("%d\n", --number); //-> 10
	printf("%d\n", number--); //-> 10
	printf("%d\n", ++number); //-> 10
	
	printf("%d\n", 3.14f);

	//비트 연산자
	//DataType
	int bin1 = 249;
	int bin2 = 13; //

	int binResult = bin1 & bin2;
	printf("AND : %d\n", binResult); //AND & : 둘 다 1일때만 1

	binResult = bin1 | bin2; //OR : 둘 중 하나라도 1이면 1
	printf("OR : %d\n", binResult);
	
	binResult = bin1 ^ bin2; //XOR : 두 자리 수가 달라야 1
	printf("XOR : %d\n", binResult);

	int bin3 = 3;
	binResult = bin3 << 2; // 곱하기 2
	printf("<< : %d\n", binResult);

	int bin4 = 27;
	binResult = bin4 >> 2; // 나누기 2
	printf(">> : %d\n", binResult);

	system("pause");
	return 0;
} 