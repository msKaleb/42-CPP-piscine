#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int	main() {
	std::list<int>		lst;
	std::vector<int> 	vec;
	std::deque<int>		deq;

	// std::cout <<"pos " << pos << std::endl;
	for (int i = 0; i < 60; i++) {
		lst.push_front(i);
		vec.push_back(i + 2);
		deq.push_back(i * -1);
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

	try {
		easyfind(deq, -20);
		easyfind(deq, -50);
		easyfind(deq, -60);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
