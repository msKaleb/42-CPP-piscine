#include <vector>
#include <list>
#include <map>
#include "easyfind.hpp"

int	main() {
	std::list<int>		lst;
	std::vector<int> 	vec;

	// std::cout <<"pos " << pos << std::endl;
	for (int i = 0; i < 60; i++) {
		lst.push_front(i);
		vec.push_back(i + 2);
	}

	try {
		easyfind(lst, 20);
		easyfind(lst, 50);
		easyfind(lst, 60);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		easyfind(vec, 20);
		easyfind(vec, 50);
		easyfind(vec, 60);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
