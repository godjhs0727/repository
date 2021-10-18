#include <iostream>
#include <string>
using namespace std;

int main()
{
	string text;
	cout << "아래에 한 줄을 입력하세요.exit를 입력하면 종료합니다." << endl;
	while (1)
	{
		cout << ">>";
		getline(cin, text);
		if (text == "exit")
			break;
		int size = text.length();
		int n = size / 2;
		for (int i = 0; i < n; i++)
		{
			char temp = text[i];
			text[i] = text[size - i - 1];
			text[size - i - 1] = temp;
		}
		cout << text << endl;
	}
}