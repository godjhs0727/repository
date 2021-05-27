#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num1;
	int num2;
public:
	SoSimple(int n1, int n2)
		:num1(n1),num2(n2){}
	/*explicit을 앞에 붙이면 묵시적변환을 막아준다. 가독성 향상*/
	/*explicit*/SoSimple(const SoSimple &copy) //SoSimple 객체를 인자로 받는 생성자 추가, const를 넣어 원본을 변경시키는 것은 복사의 개념을 무너뜨리지 않게 실수를 막자
		:num1(copy.num1), num2(copy.num2) //이니셜라이저를 이용해서 멤버 대 멤버의 복사를 진행
	{
		cout << "Called SoSimple(&copy)" << endl; //호출 확인용 문장
	}
	void ShowSimpleData()
	{
		cout << num1 << endl;
		cout << num2 << endl;
	}
};

int main()
{
	SoSimple sim1(15, 30);
	cout << "생성 및 초기화 직전" << endl;
	SoSimple sim2 = sim1; //SoSimple sim2(sim1); 과 동일하다.
	cout << "생성 및 초기화 직후" << endl;
	sim2.ShowSimpleData();

	return 0;
}