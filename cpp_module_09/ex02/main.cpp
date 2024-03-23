#include "PmergeMe.hpp"

/**
 * @todo remove Wno-unused
  */
int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "Series of numbers needed" << std::endl;
		return 1;
	}

	std::string	numbers = "";
	for (int i = 1; i < argc; i++) {
		numbers += argv[i];
		numbers += " ";
	}

	try {
		PmergeMe	p(numbers);

		std::cout << "Before: " << numbers << std::endl;
		std::cout << "After:  " << p.getSortedVector() << std::endl;
	} catch (PmergeMe::NotInt& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
