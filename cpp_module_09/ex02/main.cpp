#include "PmergeMe.hpp"

/**
 * @todo remove Wno-unused
  */
int main(int argc, char* argv[]) {
	// first check the number of arguments
	if (argc < 2) {
		std::cout << "Series of numbers needed" << std::endl;
		return 1;
	}

	// get the whole list of numbers
	std::string	numbers = "";
	for (int i = 1; i < argc; i++) {
		numbers += argv[i];
		numbers += " ";
	}

	PmergeMe	p;
	try {
		// compute
		p.sortNumbers(numbers);
		// print both the unsorted and sorted lists
		std::cout << WHITE 
			<< "Before:           " << numbers << RESET << std::endl;
		std::cout << BLUE 
			<< "After <vector>:   " << p.getSortedVector() << RESET <<std::endl;
		std::cout << YELLOW 
			<< "After <list>:     " << p.getSortedList() << RESET <<std::endl;

		// print the computation time for each container
		std::cout << GREEN << "Time to process a range of " 
				<< p.getSortedVector().size() 
				<< " elements with std::vector: " 
				<< p.getVecTime() << "μs" << RESET << std::endl;

		std::cout << MAGENTA << "Time to process a range of "
				 << p.getSortedList().size() 
				 << " elements with std::list:   " 
				 << p.getListTime() << "μs" << RESET << std::endl;
	
	// error catching
	} catch (PmergeMe::NotInt& e) {
		std::cout << e.what() << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
