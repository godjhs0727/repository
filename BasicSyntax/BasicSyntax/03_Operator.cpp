#include <stdio.h>
#include <Windows.h>

int main()
{
	int result;
	int a = 10, b = 3;
	
	//��� ����(���׿�����)
	result = a + b;
	printf("���� ��� : %d\n", result);

	result = a - b;
	printf("���� ��� : %d\n", result);

	result = a * b;
	printf("���� ��� : %d\n", result);

	result = a / b;
	printf("������ ��� : %d\n", result);

	result = a % b;
	printf("������ ��� : %d\n", result);

	//Cast
	float result2;
	result2 = (float)a / (float)b; //����� cast
	printf("������ ���2 : %f\n", result2);

	double c = 3;
	printf("��� : %f\n", a / c); //�Ͻ��� cast
	
	result2 = (a + 1) * (b * 2); //-> ���� ���? -> 16
	printf("��� : %f\n", result2);
	
	//���׿���(��������)
	printf("-------------------------------\n");
	int num1, num2, num3, num4, num5;
	num1 = num2 = num3 = num4 = num5 = 1;
	
	num1 += 1; //num1 = num1 + 1;
	printf("num1 + 1 = %d\n", num1);

	//++, --
	//++num3; // + 1
	//printf("Prefix : %d\n", num3);

	//num4++; //num4 = num4 -> ���� �����;� + 1
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

	//��Ʈ ������
	//DataType
	int bin1 = 249;
	int bin2 = 13; //

	int binResult = bin1 & bin2;
	printf("AND : %d\n", binResult); //AND & : �� �� 1�϶��� 1

	binResult = bin1 | bin2; //OR : �� �� �ϳ��� 1�̸� 1
	printf("OR : %d\n", binResult);
	
	binResult = bin1 ^ bin2; //XOR : �� �ڸ� ���� �޶�� 1
	printf("XOR : %d\n", binResult);

	int bin3 = 3;
	binResult = bin3 << 2; // ���ϱ� 2
	printf("<< : %d\n", binResult);

	int bin4 = 27;
	binResult = bin4 >> 2; // ������ 2
	printf(">> : %d\n", binResult);

	system("pause");
	return 0;
} 