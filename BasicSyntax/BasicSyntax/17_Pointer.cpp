#include <stdio.h>
#include <Windows.h>

int main()
{	
	//�ٽ�1. �ּҸ� ������ �� ����
	//�ٽ�2. (�ּҿ� + �����ڸ� ����ϸ�, Ÿ���� ����Ʈ ����ŭ �ǳʶ� ���� �ּ� �ڸ���)
	char a = 10; //�ּҿ��ٰ� ������ �ϸ� �� Ÿ���� ����Ʈ �� ��ŭ ������.
	printf("a�� ���� %d �̴�.\n", a);
	printf("a + 1 �� ���� %d �̴�.\n", a + 1);

	printf("a�� �ּҴ� %x �̴�.\n", &a);
	printf("a�� �ּ� + 1�� %x �̴�.\n", &a + 1);

	//�����Ͷ�? �ּҸ� ������ �� �ִ� ������ Ÿ���̴�. ������Ÿ�� �ڿ� ���� ������ �װ� �������̴�.
	char* ptr;

	ptr = &a;
	printf("ptr�� ���� %x\n", ptr);
	
	//�ٽ�3. ������ ����
	float pi = 3.141592f;
	float* pPi = &pi;

	printf("pi : %f\n", pi);
	printf("pPi : %x\n", pPi);
	printf("pPi : %f\n", *pPi);

	*pPi = 99.9f;
	printf("pi : %f\n", pi);

	//�ٽ�4. ���� �Ҵ�(Dynamic Allocate) Stack, Heap �����غ��� ����Ÿ�� ��Ÿ��...
	//���� ���ھ߱� �迭 �̿��ؼ�.



	system("pause");
	return 0;
}