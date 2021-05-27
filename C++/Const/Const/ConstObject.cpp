#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) :num(n){}
	SoSimple& AddNum(int n)
	{
		num += n;
		return *this;
	}
	void ShowData() const
	{
		cout << "num: " << num << endl;
	}
};
int main()
{
	const SoSimple obj(7);
	//obj.AddNum(20); obj가 const로 정의했기때문에 불가능
	obj.ShowData(); //ShowData()함수는 const정의가 되어있기 때문에 가능

	return 0;
}