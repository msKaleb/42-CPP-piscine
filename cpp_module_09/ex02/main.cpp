#include "PmergeMe.hpp"
#include <cstdlib>
#include <sstream>

size_t	jacobsthal(size_t n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return jacobsthal(n - 1) + 2 * (jacobsthal(n - 2));
}
int main(int argc, char* argv[]) {
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
	std::stringstream	ss(numbers);
	// int*	chain = new int[size / 2];
	while (ss >> item) {
		std::cout << item << std::endl;
		
	}

	return (0);
}
