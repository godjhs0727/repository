#include <iostream>
using namespace std;

int main() {
	int ch;
	cin.ignore(100, ';');
	while ((ch = cin.get()) != EOF){ cout << (char)ch; }
}