#include <iostream>
#include <vector>
#include <string>
#include <utility>

int main() {
	
	std::vector<std::pair<int, std::string>> v;

	v.emplace_back(1, "first");
	v.emplace_back(2, "second");

	for (auto n : v) {
		std::cout << n.first << " " << n.second << std::endl;
	}

	return 0;
}
