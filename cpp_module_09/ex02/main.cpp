#include "PmergeMe.hpp"
#include <cstdlib>

size_t	jacobsthal(size_t n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return jacobsthal(n - 1) + 2 * (jacobsthal(n - 2));
}
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
	PmergeMe	p(numbers); // get size wit stringstream
	/* std::stringstream	ss(numbers);
	int*	intNumbers = new int[size];
	size = 0;
	while (ss >> item) {
		intNumbers[size++] = std::strtol(item.c_str(), NULL, 10);
		std::cout << "Position " << size - 1 << ": " << intNumbers[size - 1] << std::endl;
	} */

 // create double pointer array (in constructor?) ******************************
	/* int**	chain = new int*[size / 2];
	for (size_t i = 0; i < (size - 1); i += 2) {
		chain[i] = new int[2];
		chain[i][0] = std::min(intNumbers[i], intNumbers[i + 1]);
		chain[i][1] = std::max(intNumbers[i], intNumbers[i + 1]);
		std::cout << "chain a " << size - 1 << ":  " << chain[i][1] << std::endl;
		std::cout << "chain b " << size - 1 << ": " << chain[i][0] << std::endl;
	} */
 // ****************************************************************************

 // delete chain ***************************************************************
	/* delete[]intNumbers;
	for (size_t i = 0; i < (size / 2); i++) {
		delete[]chain[i];
	}
	delete[]chain; */
 // ****************************************************************************

	return (0);
}
