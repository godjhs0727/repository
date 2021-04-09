#include <iostream>
using namespace std;

class CountryArea
{
public:
	const static int RUSSIA =		1707540;
	const static int CANADA =		998467;
	const static int CHINA =		957290;
	const static int SOUTH_KOREA =	9922;
};
int main()
{
	cout << "러시아 면적: " << CountryArea::RUSSIA << "㎢" << endl;
	cout << "캐나다 면적: " << CountryArea::CANADA << "㎢" << endl;
	cout << "중국 면적: " << CountryArea::CHINA << "㎢" << endl;
	cout << "한국 면적: " << CountryArea::SOUTH_KOREA << "㎢" << endl;

	//const로 상수화 되어있고 static으로 객체 생성 없이 바로 접근이 가능하게 할수 있는 const static 멤버변수
	return 0;
}