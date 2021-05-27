#include <iostream>
using namespace std;

class Base
{
private: //여기 클래스 이외에 어느곳에서도 땡겨 쓸수 없다.
	int num1;
protected: //상속받은곳에서만 땡겨 쓸수 있다.
	int num2;
public: //어디서든
	int num3;

	Base() :num1(1),num2(2),num3(3){}
};
class Derived : public Base{}; //public으로 상속정의를 했기에 바깥에서 사용 가능
//private상속은 의미없는 상속이고, protected상속은 Derived로부터 상속받은 클래스만 사용이 가능
int main()
{
	Derived drv;
	cout << drv.num3 << endl; //num3만 사용 가능한 이유는 num3만 Base에서 public이고, num1은 private라서 안되고 num2는 protected라 상속 받은곳에서만 쓸수 있다.
	return 0;
}