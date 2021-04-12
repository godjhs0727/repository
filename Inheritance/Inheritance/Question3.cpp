/*
����1)
���簢���� �ǹ��ϴ� Square Ŭ������ ���簢���� �ǹ��ϴ� Rectangle Ŭ������ �����ϰ���
�Ѵ�. �׷��� ���簢���� ���簢���� ��������, ������ ���·� Ŭ������ ��Ӱ��踦 �����ϰ���
�Ѵ�.
����2)
'å'�� �ǹ��ϴ� BookŬ������ '���� å'�� �ǹ��ϴ� EbookŬ������ �����ϰ��� �Ѵ�. '���� å'�� 'å'�� ��������,
��Ӱ��踦 �����ϰ��� �Ѵ�.
main�Լ��� �Բ� ������ �����ϵ��� Ŭ������ �ϼ�����.
*/
#include <iostream>
#include <cstring>
using namespace std;

class Rectangle
{
private:
	int num1;
	int num2;
public:
	Rectangle(int n1, int n2) :num1(n1), num2(n2)
	{}
	void ShowAreaInfo()
	{
		cout << "����: " << num1 * num2 << endl;
	}
};

class Square : public Rectangle
{
public:
	Square(int n1)
		:Rectangle(n1, n1)
	{}
};

class Book
{
private:
	char* title;	//å�� ����
	char* isbn;		//����ǥ�ص�����ȣ
	int price;		//å�� ����
public:
	Book(const char* tle, const char* num, int pr)
		:price(pr)
	{
		title = new char[strlen(tle) + 1];
		isbn = new char[strlen(num) + 1];
		strcpy(title, tle);
		strcpy(isbn, num);
	}
	void ShowBookInfo()	const
	{
		cout << "����: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "����: " << price << endl;
	}
	~Book()
	{
		delete[] title;
		delete[] isbn;
	}
};

class Ebook : public Book
{
private:
	char* DRMKey;	//���Ȱ��� Ű
public:
	Ebook(const char* tle, const char* num, int pr, const char* key)
		:Book(tle, num, pr)
	{
		DRMKey = new char[strlen(key) + 1];
		strcpy(DRMKey, key);
	}
	void ShowEBookInfo()
	{
		ShowBookInfo();
		cout << "����Ű: " << DRMKey << endl;
	}
	~Ebook()
	{
		delete[] DRMKey;
	}
};

int main()
{
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square rec2(7);
	rec2.ShowAreaInfo();
	cout << endl;

	Book book("���� C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	Ebook ebook("���� C++", "555-12345-890-1", 10000, "qwrskjf999");
	ebook.ShowEBookInfo();

	return 0;
}