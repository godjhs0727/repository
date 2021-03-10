/*
문제1)
사용자로부터 총 5개의 정수를 입력 받아서, 
그 합을 출력하는 프로그램을 작성해 보자.
단, 프로그램의 실행은 다음과 같이 이뤄져야 한다.
*/
/*
실행 예)
1번째 정수 입력 : 1
2번째 정수 입력 : 2
3번째 정수 입력 : 3
4번째 정수 입력 : 4
5번째 정수 입력 : 5
합계: 15

*/
/*
문제2)
프로그램 사용자로부터 이름과 전화번호를 문자열의 형태로 입력 받아서,
입력 받은 데이터를 그대로 출력하는 프로그램을 만들어보자.
*/
/*
문제3)
숫자를 하나 입력 받아서 그 숫자에 해당하는 구구단을 출력하는 프로그램을 작성해보자.
예를 들어서 사용자가 5를 입력한다면 구구단에서 5단을 출력해야한다.
*/
/*
문제4)
판매원들의 급여 계산 프로그램을 작성해 보자. 이 회사는 모든 판매원에게
매달 50만원의 기본 급여와 물품 판매 가격의 12%에 해당하는 돈을 지급한다.
예를 들어서 민수라는 친구의 이번 달 물품 판매 금액이 100만원이라면 50+100*0.12=62,
따라서 62만원을 급여로 지급 받는다. 단, 아래의 실행의 예에서 보이듯이 이러한 급여의 계산은
-1이 입력될 때까지 계속 되어야 한다.
*/
/*
실행 예)
판매 금액을 만원 단위로 입력(-1 to end):100
이번 달 급여: 62만원
판매 금액을 만원 단위로 입력(-1 to end):200
이번 달 급여: 74만원
판매 금액을 만원 단위로 입력(-1 to end):-1
프로그램을 종료합니다.
*/
#include <iostream>
using namespace std;

int main()
{
	//문제1)
	int result = 0;

	for (int i = 1; i <= 5; i++)
	{
		int val;

		cout << i << "번째 정수 입력: ";
		cin >> val;
		result += val;
	}
	cout << "합계: " << result << endl;
	printf("\n");
	
	//문제2)
	char name[100];
	char num[100];
	cout << "이름을 문자열로 입력 : ";
	cin >> name;
	cout << "전화번호를 문자열로 입력 : ";
	cin >> num;
	cout << "이름은 : " << name << "\n" << "전화번호는 : " << num << endl;

	//문제3)

	int n;
	cin >> n;
	for (int i = 1; i < 10; i++)
	{
		cout << n << " x " << i << " = " << n * i << endl;
	}

	//문제4)
	int bGame = true;
	while(bGame)
	{
		float n;
		cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
		cin >> n;
		
		if (n == -1)
			bGame = false;
		else
		{
			cout << "이번 달 급여: " << 50 + n * 0.12 << "만원" << endl;
		}
	}
	cout << "프로그램을 종료합니다." << endl;
	system("pause");
	return 0;
}