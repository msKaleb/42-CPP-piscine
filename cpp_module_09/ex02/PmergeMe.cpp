#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	// std::cout << "PmergeMe: Default Constructor Called" << std::endl;
}

PmergeMe::~PmergeMe() {
	// std::cout << "PmergeMe: Destructor Called" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const &copy) {
	// std::cout << "PmergeMe: Copy Constructor Called" << std::endl;
	if (this != &copy)
		*this = copy;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &rhs) {
	// std::cout << "PmergeMe: Copy Assignment Operator Called" << std::endl;
	if (this != &rhs)
	{
		//	this->attributes = rhs.attributes;
		//	...
	}
	return (*this);
}

PmergeMe::PmergeMe(std::string const& numbers, size_t size) {
	std::stringstream	ss(numbers);
	std::string			item;

	int*	intNumbers = new int[size];
	size = 0;
	while (ss >> item) {
		intNumbers[size++] = std::strtol(item.c_str(), NULL, 10);
		std::cout << "Position " << size - 1 << ": " << intNumbers[size - 1] << std::endl;
	}

 // create double pointer array (in constructor?) ******************************
	int**	chain = new int*[size / 2];
	for (size_t i = 0; i < (size - 1); i += 2) {
		chain[i] = new int[2];
		chain[i][0] = std::min(intNumbers[i], intNumbers[i + 1]);
		chain[i][1] = std::max(intNumbers[i], intNumbers[i + 1]);
		std::cout << "chain a " << size - 1 << ":  " << chain[i][1] << std::endl;
		std::cout << "chain b " << size - 1 << ": " << chain[i][0] << std::endl;
	}
 // ****************************************************************************

}