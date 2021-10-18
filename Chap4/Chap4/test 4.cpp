#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
	string text;
	srand((unsigned)time(0)); //시작할 때마다, 다른 랜덤수 발생seed설정

	cout << "아래에 한 줄을 입력하세요. (exit를 입력하면 종료합니다)" << endl;
	while (1) {
		cout << ">>";
		getline(cin, text);
		if (text == "exit")
			break;
		if (text == "")
			continue;
		int size = text.length();
		int index = rand() % size;
		int c = rand() % 26;
		char changeChar = 'a' + c;	//새로 삽입할 문자
		if (text[index] == 'a' + c)changeChar = 'A' + c;
		text[index] == changeChar;
		cout << text << endl;
	}
}
