#include <iostream>
#include <cstring>
using namespace std;

class Girl; //���漱�� ���߿� ����
class Boy
{
private:
	int height;
	friend class Girl; //Girl Ŭ������ ���� friend����
public:
	Boy(int len):height(len){}
	void ShowYourFriendInfo(Girl &frn); //Girl Ŭ������ friend���� ���� ������ �𸣴� �ϴ� ���漱��
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
	friend class Boy; // Boy Ŭ������ ���� friend����
};

//�Լ� ȣ�� ������ ���� ���� ������ ���Ǵ� �ڷ� ����.
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