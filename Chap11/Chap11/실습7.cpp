#include <iostream>
#include <string>
using namespace std;

class Phone {
	string name, telnum, address;
public:
	Phone(string name = "", string telnum = "", string adress = "") {
		this->address = adress;
		this->name = name;
		this->telnum = telnum;
	}
	friend ostream& operator << (ostream& outs, Phone phone);
	friend istream& operator >> (istream& ins, Phone phone);
};

int main() {
	Phone girl, boy;
	cin >> girl >> boy;
	cout << girl << boy << endl;
	return 0;
}

ostream& operator<<(ostream& outs, Phone phone)
{
	outs << "(" << phone.name << ", ";
	outs << phone.telnum << ", ";
	outs << phone.address << ")";
	return outs;
}

istream& operator>>(istream& ins, Phone phone)
{
	cout << "�̸�:";
	getline(ins, phone.name);
	cout << "��ȭ��ȣ:";
	getline(ins, phone.telnum);
	cout << "�ּ�:";
	getline(ins, phone.address);
	return ins;
}
