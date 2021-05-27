#include <iostream>
using namespace std;
/*
2���� ���󿡼��� ��ǥ�� ǥ���� �� �ִ� ����ü�� ������ ���� �����Ͽ���.
*/
struct Point
{
	int xpos;
	int ypos;

	/*
	���� ����ü�� ������� ������ �Լ��� �����ϰ��� �Ѵ�(�ڼ��� ����� ������ ���� ���ؼ� Ȯ��
	�ϵ��� �Ѵ�.)
	*/
	void MovePos(int x, int y) //���� ��ǥ �̵�
	{
		xpos += x;
		ypos += y;
	}
	void AddPoint(const Point &pos) //���� ��ǥ ����
	{
		xpos += pos.xpos;
		ypos += pos.ypos;
	}
	void ShowPosition() //���� x, y ��ǥ ���
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};
//��, ���� �Լ����� ����ü �ȿ� ���Ǹ� �ؼ� ������ ���·� main�Լ��� ������ �� �־�� �Ѵ�.
int main()
{
	Point pos1 = { 12, 4 };
	Point pos2 = { 20,30 };

	pos1.MovePos(-7, 10);
	pos1.ShowPosition();	//{5, 14} ���

	pos1.AddPoint(pos2);
	pos1.ShowPosition();	//{25, 44} ���
	
	return 0;
}
//�׸��� ���� �ּ����� ���̵��� �������� ������ ������ �Լ��� ���ǵǾ�� �Ѵ�.