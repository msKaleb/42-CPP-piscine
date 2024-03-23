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

		std::cout << "Before:           " << numbers << std::endl;
		std::cout << "After <vector>:   " << p.getSortedVector() << std::endl;
		std::cout << "After <list>:     " << p.getSortedList() << std::endl;
		std::cout << "Time to process a range of " 
				<< p.getSortedVector().size() 
				<< " elements with std::vector: " 
				<< p.getVecTime() << "μs" << std::endl;

		std::cout << "Time to process a range of "
				 << p.getSortedList().size() 
				 << " elements with std::list:   " 
				 << p.getListTime() << "μs" << std::endl;
	} catch (PmergeMe::NotInt& e) {
		std::cout << e.what() << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
