#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
	int bullet;
public:
	Gun(int bnum):bullet(bnum)
	{}
	void Shot()
	{
		cout << "BBANG!" << endl;;
		bullet--;
	}
	void GetBullet()
	{
		cout << bullet << endl;
	}
};

class Police
{
private:
	int handcuffs;
	Gun* pistol; //소유하고 있는 권총
public:
	Police(int bnum, int bcuff)
		:handcuffs(bcuff)
	{
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}
	void PutHandcuff()
	{
		cout << "SNAP!" << endl;
		handcuffs--;
	}
	void Shot()
	{
		if (pistol == NULL)
		{
			cout << "No Way" << endl;
		}
		else
			pistol->Shot();
	}
	void HowMany()
	{
		cout << "Bullet: ";
		if (pistol != NULL)
			pistol->GetBullet();
		else
			cout << 0 << endl;
		cout << "Handcuffs: " << handcuffs << endl;
	}
	~Police()
	{
		if (pistol != NULL)
			delete pistol;
	}
};

int main()
{
	Police pman1(5, 3);
	pman1.Shot();
	pman1.PutHandcuff();
	pman1.HowMany();
	Police pman2(0, 3);
	pman2.Shot();
	pman2.PutHandcuff();
	pman2.HowMany();
	return 0;
}