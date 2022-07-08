#include <iostream>
#include <string>
#include <vector>
#include <thread>

template <typename T>
T add(T a, T b) {
	return a + b;
}

class Cat {
private:
	int a;
public:
	int set(int a) {
		return this->a = a;
	}
	void get() {
		std::cout << a << std::endl;
	}
	Cat() {
		std::cout << "constructor" << std::endl;
	}
	Cat(int a) {
		std::cout << a << std::endl;
		this->a = a;
	}
	~Cat() {
		std::cout << "Destructor" << std::endl;
	}
};

void fn(int a, std::string s) {
	std::cout << a << " " << s << std::endl;
}

int divide(int a, int b) {
	if (b == 0) {
		throw std::exception();
	}
	return a / b;
}

int main() {
	
	int* p = new int(3);
	std::cout << *p << std::endl;
	delete p;

	int a = 1, b = 3;
	std::cout << add(a, b) << std::endl;

	Cat* cat = new Cat(3);
	Cat* something = new Cat();
	cat->get();
	something->set(5);
	something->get();
	delete cat;
	delete something;
	std::cout << std::endl;
	try {
		std::cout << divide(10, 0) << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "exception catched" << std::endl;
	}
	std::cout << std::endl;
	std::thread t1(fn, a, "thread test");
	t1.join();

	std::vector<std::string> v;
	v.emplace_back("first");
	v.emplace_back("second");
	for (auto num : v) {
		std::cout << num << std::endl;
	}

	return 0;
}
