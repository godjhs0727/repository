#include <stdio.h>
#include <Windows.h>

int main()
{
	//���� : ������ ��� ������ �� �� ���� �� & ���� �����ϱ� ���� �޸� ����
	int a; //������ ����, int : DataType(�ڷ���)
	
	a = -5; //������ �ʱ�ȭ(Initialze)
	a = 20; //������ �ʱ�ȭ(Initialze)
	a = 2000000000;
	printf("a�� ���Ե� ���� %d �Դϴ�.\n", a);

	float fNumber; //float : �Ǽ��� �����ϴ� Ÿ��. 4 Bytes
	fNumber = 3.14f;
	printf("fNumber�� ���Ե� ���� %.2f �Դϴ�.\n", fNumber);

	//�������� �����ϴ� �κ�
	double dNumber; //�Ǽ�, 8 Bytes
	long lNumber; //����, 4 Bytes
	long long llNumber; //����, 8 Bytes
	char ascii; //����(���ĺ� �ѱ���)
	bool isDead; //��(1 true), ����(0, false), 1Byte

	unsigned int violent; //
	violent = -1;
	printf("������ ���¼��� %u\n", violent);

	int weWantedName;
	//�۸� ��Ģ
	// -> ��ҹ��� ����
	// -> �ѹ� ����� ������ ���� �Լ� ������ �ٽ� �缱���� �Ұ�����
	// -> ������ �� �տ��� ���� �Ұ�
	// -> Ư������ �Ұ� (_ �� ����)
	// -> �̹� ����� Ű����� ��� �Ұ�
	// -> ������� �Ұ�

	int player1CurrentHp; //Camel
	int player1_current_hp; //Snake
	
	
	system("pause");
	return 0;
}