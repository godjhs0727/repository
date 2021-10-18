/*String 클래스를 이용하여 빈칸을 포함하는 문자열을 입력받고 문자열에서 'a'가 몇 개 있는지
출력하는 프로그램을 작성해보자*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	string text;
	cout << "문자열 입력>> ";
	getline(cin, text); //빈 칸을 포함하는 문자열 한 라인 입력

	int count = 0, index = 0;
	while (1) {
		index = text.find('a', index); //index부터 'a'찾기
		if (index = -1)
			break;
		count++;
		index++; //현재 찾은 바로 다음 위치부터 찾기 위해
	}
	cout << "문자 a는 " << count << "개 있습니다." << endl;
}