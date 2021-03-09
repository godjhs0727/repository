#include <stdio.h>
#include <Windows.h>
#include <time.h>//.h�� c�� ���°͵�
#include <string>
#include <iostream>//h�Ⱥٴ¾ֵ��� c++���� ���°�
using namespace std;

//�Լ� ��� ����
//-> 1. �ڵ��� ���뼺
//-> 2. ������ ���

int WhatIsFunction() // <- �Լ��� �����(Prototype)
{
	//-> �Լ��� ����
	printf("�Լ��� ���迡 ���� ���� ȯ��\n");
	
	return 0;//<- �Լ��� ���ϰ�
}



int Max(int a, int b)
{
	int max = a > b ? a : b; //���� ������ ���̸� �տ� �ɸ��� �����̸� �ڿ� �ִ°��� �ɸ��� a Or b a�� b ���� ũ�� a�� �ɸ��� �ƴϸ� b�� �ɸ�
	printf("Max : %d\n", max);

	return 0;
}

int WhatIsReturn(int range)
{
	printf("0~����� �Է��� �� ���� �ȿ��� ������ �ϳ��� �˷��帳�ϴ�\n");
	srand((UINT)time(NULL));
	int result = rand() % range;

	return result; //*ptr�� ������ �Լ��� *�����ͷ� ������� �Ѵ�. int* WhatIsReturn -> int* ptr ����
}

char ToSwapCharacter(char ascii)
{
	char temp = 'a';

	if (ascii >= 'a' && ascii <= 'z')
		temp = ascii - 32;
	else if (ascii >= 'A' && ascii <= 'Z')
		temp = ascii + 32;
	else
	{
		printf("�Է� ������ ����� ���Դϴ�.!\n");
		return ascii;
	}

	return temp;
}

void WhatIsVoid()
{
	printf("1. ���� ������ �����ϴ�! �Ķ���ʹ� ���� �� �ֽ��ϴ�.\n");
	return; //�ڿ� 2���� ǥ�ð� ���� �ʴ´�.
	printf("2. ���� ������ �����ϴ�! �Ķ���ʹ� ���� �� �ֽ��ϴ�.\n");
}

string WhatIsPrototype();
void WhatIsPrototype2(); //���� ����� ctrl .Ȥ�� alt enter �׸��� ���� �����

void WhatIsOverloading();//Ŭ������ ���� �����ֱ� ���� �̸��� �Լ��� ����� ����
void WhatIsOverloading(int a); // �Լ��� �̸��� �Ȱ����� �Ȱ��� ����� �ٸ��� ����ϱ� ���ؼ�? ������?
void WhatIsOverloading(int a, int b);
void WhatIsOverloading(float a);

template<typename T>//T�� ������ ������ Ÿ��
void WhatIsTemplate(T val)//���ø��� ��� ������Ÿ���� ������ �־ �װ� ������ ���ۿ��ϼ� �ִ�.
{
	cout << val << endl;
}

int main()
{

	////�Լ���?
	//WhatIsFunction(); //<- �Լ��� ȣ��(Call)

	////�Ķ���Ͷ�?(����)
	//int input1, input2; //Max �Լ��� �����ؼ� �ϴ� ȣ�� ��� Call By Value
	//printf("����1 �Է� :");
	//scanf("%d", &input1);
	//printf("����2 �Է� :");
	//scanf("%d", &input2);

	//Max(input1, input2); //<- �Ķ���Ͱ� �����ϴ� �Լ�(����)
	//Max(7, 9); //%d������ ���ڸ� �ᵵ ����
	//�����̶�?
	//int result = WhatIsReturn(5);
	//printf("%d\n", result);
	//while (true)
	//{
	//	char input;
	//	scanf(" %c", &input); //������ �ξ� ������Ѵ�.?
	//	char result = ToSwapCharacter(input);
	//	printf("��� : %c\n", result);
	//}

	//void* a; //�����ʹ� �ּҶ� ��� 4����Ʈ ��� void*�� ���� ����
	//Void �Լ���?
	WhatIsVoid();
	
	//���漱���̶�?
	printf("%s\n", WhatIsPrototype().c_str()); //���ϰ��� ������. �Լ��� �����鼭 ������ ����� �״´�.

	//�����ε��̶�? -> �Ķ���ͷ� ����
	// ->1) �Ķ������ Ÿ���� �޶����
	WhatIsOverloading(); //�ѹ� �����غ��� call by value, address, reference
	WhatIsOverloading(30);
	WhatIsOverloading(30.0f);
	WhatIsOverloading(10, 20);

	//���ø� �Լ���?
	WhatIsTemplate(9); //T�� �Ķ���� Ÿ���� ���� �Ǵ��ϰ� �װɷ� �ٲ�� �̰� int�� �ٲ�
	WhatIsTemplate(99.9f);
	WhatIsTemplate('Z');
	WhatIsTemplate(new int);

	//auto a = "a"; // voidó�� ���� �ϸ� �������� ���δ� ��Ȯ�� ������ Ÿ���� ũ�⸦ �˼� ����. //������ Ÿ���� ���� �𸦶� �׳� �˾Ƽ� ã���ش�.

	system("pause");
	return 0;
}

string WhatIsPrototype()
{
	printf("���� �����Լ����� ������ ����Ǿ� �ֽ��ϴ�.\n");
	return "���� ���� �ʹ�"; //���� ����;;
}

void WhatIsPrototype2()
{
	printf("�ù�\n");
}

void WhatIsOverloading()
{
	printf("���� �Ķ��� ����\n");
}

void WhatIsOverloading(int a)
{
	printf("���� 1�Ķ��̴�. : %d\n", a);
}

void WhatIsOverloading(int a, int b)
{
	printf("���� 2�Ķ��̴�. : %d, %d\n", a, b);
}

void WhatIsOverloading(float a)
{
	printf("(float)���� 1�Ķ��̴�. : %f\n", a);
}

