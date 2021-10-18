#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
	string tel;
public:
	Person();
	string getName() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel);
};

Person::Person()
{
	this->name = "";
	this->tel = "";
}

void Person::set(string name, string tel)
{
	this->name = name;
	this->tel = tel;
}
class PersonManager {
	Person* p;
	int size;
public:
	PersonManager(int n) {
		p = new Person[n];
		size = n;
		string name, tel;
		cout << "이름과 전화 번호를 입력해 주세요" << endl;
		for (int i = 0; i < size; i++) {
			cout << "사람 " << i + 1 << ">>";
			cin >> name >> tel;
			p[i].set(name, tel);
		}
	}
	void show();
	void search();
	~PersonManager() {
		delete[] p;
	}
};
int main() {
	PersonManager manager(3);
	manager.show();
	manager.search();
}

void PersonManager::show()
{
	cout << "모든 사람의 이름은 ";
	for (int i = 0; i < size; i++) {
		cout << p[i].getName() << ' ';
	}
	cout << endl;
}

void PersonManager::search()
{
	string name;
	cout << "전화번호 검색합니다. 이름을 입력하세요>>";
	cin >> name;
	for (int i = 0; i < size; i++) {
		if (name == p[i].getName()) {
			cout << "전화번호는 " << p[i].getTel() << endl;
			return;
		}
	}
	cout << "없는 사람입니다" << endl;
}

