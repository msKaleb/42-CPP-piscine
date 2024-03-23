#include "PmergeMe.hpp"
#include <cstdlib>

/**
 * @todo check all parameters are digits
  */
int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "Series of numbers needed" << std::endl;
		return 1;
	}

	std::string	numbers = "";
	std::string	item;
	size_t		size = 0;

	for (int i = 1; i < argc; i++) {
		if (std::strtol(argv[i], NULL, 10) < 0) {
			std::cout << "Only positive integers" << std::endl;
			return 1;
		}
		numbers += argv[i];
		numbers += " ";
		size++;
	}
	std::cout << "Before: " << numbers << std::endl;
	try {
		PmergeMe	p(numbers);

		std::cout << "After:  " << p.getSortedVector() << std::endl;
	} catch (PmergeMe::NotInt& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
