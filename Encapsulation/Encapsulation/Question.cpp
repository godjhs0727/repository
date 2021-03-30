/*
������ Point Ŭ������ ������� �Ͽ�(Ȱ���Ͽ�) ���� �ǹ��ϴ�
Circle Ŭ������ ��������
*/
#include <iostream>
using namespace std;
class Point
{
private:
	int xpos, ypos;
public:
	void Init(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	void ShowPointInfo()const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};
/*
Circle ��ü���� ��ǥ���� ��ġ ����(���� �߽���ǥ)�� �������� ���� ������ ���� �� ����� ��
�־�� �Ѵ�. �׸��� �������� ������ Circle Ŭ������ ������� Ring Ŭ������ ��������. ����
�� ���� ������ ǥ�� �����Ϲ��� (�ٱ��� ���� ���� ��), �� ���� Circle ��ü�� ������� ���ǰ�
�����ϴ�. ����� ���� ���� �ٱ��� ���� �߽���ǥ�� �����ϴٸ� �β��� ������ ���� ǥ���ϴ� ����
�Ǹ�, �߽���ǥ�� �������� �ʴٸ� �β��� �������� ���� ���� ǥ���ϴ� ���� �ȴ�. �̷��� �ؼ�
Ŭ������ ���ǰ� �Ϸ�Ǿ��ٸ�, ���� main �Լ��� ������� ������ ��Ű��.
*/

class Circle
{
private:
	int rad; //������
	Point center; //���� �߽�
public:
	void Init(int x, int y, int r)
	{
		rad = r;
		center.Init(x, y);
	}

	void ShowCircleInfo() const
	{
		cout << "radius : " << rad << endl;
		center.ShowPointInfo();
	}
};

class Ring
{
private:
	Circle inCircle;
	Circle outCircle;
public:
	void Init(int inX, int inY, int inR, int outX, int outY, int outR)
	{
		inCircle.Init(inX, inY, inR);
		outCircle.Init(outX, outY, outR);
	}
	void ShowRingInfo() const
	{
		cout << "Inner Circle Info..." << endl;
		inCircle.ShowCircleInfo();
		cout << "Outter Circle Info..." << endl;
		outCircle.ShowCircleInfo();
	}
};

int main()
{
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();

	return 0;
}
/*
Init�� �Լ�ȣ���� ���ؼ� ���޵� 1, 1, 4�� ���� ���� ������ �ش��ϸ� (������� X��ǥ, Y��ǥ,
������), �̾ ���޵� 2, 2, 9�� �ٱ��� ���� ������ �ش��Ѵ�(������� X��ǥ, Y��ǥ, ������),
�׸��� �������� ������ ���ų� �����ؾ� �Ѵ�.
������)
Inner Circle Info...
radius:4
[1, 1]
Outter Circle Info...
radius:9
[2, 2]
*/