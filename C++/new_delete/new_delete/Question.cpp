/*
����ü�� ���� ������ ���� �� �ִ� ����
2���� ���󿡼��� ��ǥ�� ǥ���� �� �ִ�
����ü�� ������ ���� ���� �Ͽ���.
*/
#include <iostream>
using namespace std;

typedef struct __Point
{
	int xpos;
	int ypos;
}Point;
/*
���� ����ü�� ������� �� ���� ���� ����ϴ� �Լ��� ������ ���·� ���� �ϰ� (��������� �Լ���
��ȯ�� ���ؼ� ��� �Ѵ�.)
*/
Point& pntAdder(const Point &p1, const Point &p2)
{
	Point*pptr = new Point; //new�Ҵ����� ����
	pptr->xpos = p1.xpos + p2.xpos; //pptr�� xpos�� �Ű����� p1,p2�� ��
	pptr->ypos = p1.ypos + p2.ypos; //ypos�� ���� ��
	return *pptr;
}

int main()
{
	Point *pptr = new Point;
	pptr->xpos = 3;
	pptr->ypos = 30;

	Point *pptr2 = new Point;
	pptr2->xpos = 70;
	pptr2->ypos = 7;

	Point &pref = pntAdder(*pptr, *pptr2); //�����ڷ� �ҷ���
	cout << "[" << pref.xpos << ", " << pref.ypos << "]" << endl;

	delete pptr; //Point*pptr�� ���� ����
	delete pptr2; //Point*pptr2�� ���� ����
	delete &pref; //�Լ� Point& pntAdder�� ����ִ� new �Ҵ翡 ���� ����


	return 0;
}

/*
������ �� ���� �����Ͽ�, �� �Լ��� �̿��� ���������� �����ϴ� main �Լ��� �����غ���. ��, 
*����ü Point ���� ������ ������ ������ new �����ڸ� �̿��ؼ� �����ؾ� �ϸ�, 
*�Ҵ�� �޸� ������ �Ҹ굵 ö���ؾ� �Ѵ�. 
����� �� ������ �ذ��� ���ؼ��� ���� �� ������ ���� �Ҽ� �־�� �Ѵ�.
-�����Ҵ� �� ������ �Լ��� ������ �Ű������� ���ڷ� ��� �����ؾ� �ϴ°�? (��ħǥ ��� ����´�.)
-�Լ� ���� ����� ������ ���������� ��ȯ�Ϸ��� �ش� ������ ��� �����ؾ� �ϴ°�?
*/
