#include <iostream>
#include <string>
using namespace std;

int main()
{
	string text;
	cout << "�Ʒ��� �� ���� �Է��ϼ���.exit�� �Է��ϸ� �����մϴ�." << endl;
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