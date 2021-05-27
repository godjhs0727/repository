#include <iostream>
using namespace std;

namespace Hybrid
{
	void HybFunc()
	{
		cout << "So Simple function!" << endl;
		cout << "In namespace Hybrid!" << endl;
	}
}
int main()
{
	using Hybrid::HybFunc;
	//키워드 using을 이용해서 '이름공간 Hybrid에 정의된 HyFunc를 호출할 때에는,
	//이름 공간을 지정하지 않고 호출하겠다!'는 것을 명시(선언)하고 있다.
	HybFunc();
	//이름공간 지정없이 using선언으로 HybFunc함수 호출

	/*
	cout, cin, endl 을 적용할때 원래는 std::cout 이런식으로 해주어야하는데
	using을 통하여 using std::cout; 을 하게 되면 cout만 std::cout을 사용할
	필요가 없어지고 using namespace std;를 하게 되면 std::를 쓰는 모든것이
	std::가 필요없어지게 된다.
	*/

	return 0;
}