/*
문제1)
정사각형을 의미하는 Square 클래스와 직사각형을 의미하는 Rectangle 클래스를 정의하고자
한다. 그런데 정사각형은 직사각형의 일종으로, 다음의 형태로 클래스의 상속관계를 구성하고자
한다.
문제2)
'책'을 의미하는 Book클래스와 '전자 책'을 의미하는 Ebook클래스를 정의하고자 한다. '전자 책'도 '책'의 일종으로,
상속관계를 구성하고자 한다.
main함수와 함께 실행이 가능하도록 클래스를 완성하자.
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
		cout << "면적: " << num1 * num2 << endl;
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
	char* title;	//책의 제목
	char* isbn;		//국제표준도서번호
	int price;		//책의 정가
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
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
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
	char* DRMKey;	//보안관련 키
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
		cout << "인증키: " << DRMKey << endl;
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

	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	Ebook ebook("좋은 C++", "555-12345-890-1", 10000, "qwrskjf999");
	ebook.ShowEBookInfo();

	return 0;
}