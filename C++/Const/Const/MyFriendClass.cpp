#include <iostream>
#include <cstring>
using namespace std;

class Girl; //전방선언 나중에 정의
class Boy
{
private:
	int height;
	friend class Girl; //Girl 클래스에 대한 friend선언
public:
	Boy(int len):height(len){}
	void ShowYourFriendInfo(Girl &frn); //Girl 클래스가 friend선언 할지 안할지 모르니 일단 전방선언
};

class Girl
{
private:
	char phNum[20];
public:
	Girl(const char* num)
	{
		strcpy(phNum, num);
	}
	void ShowYourFriendInfo(Boy &frn);
	friend class Boy; // Boy 클래스에 대한 friend선언
};

//함수 호출 순서에 따라서 전방 선언후 정의는 뒤로 뺐다.
void Boy::ShowYourFriendInfo(Girl & frn)
{
	cout << "Her phone Number: " << frn.phNum << endl;
}

void Girl::ShowYourFriendInfo(Boy & frn)
{
	cout << "His Height: " << frn.height << endl;
}

int main()
{
	Boy boy(180);
	Girl girl("010-1234-5678");
	boy.ShowYourFriendInfo(girl);
	girl.ShowYourFriendInfo(boy);

	return 0;
}