#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	// std::cout << "PmergeMe: Default Constructor Called" << std::endl;
}

PmergeMe::~PmergeMe() {
	// std::cout << "PmergeMe: Destructor Called" << std::endl;
	/* for (size_t i = 0; i < (_size / 2); i++) {
		delete[]_chain[i];
	}
	delete[]_chain; */
	// delete[]_tChain;
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

PmergeMe::PmergeMe(std::string const& numbers) { // get size with stringstream
	std::stringstream	ss(numbers);
	std::string			item;
	unsigned int		size = 0;

	/* int*	intNumbers = new int[size];
	while (ss >> item) {
		intNumbers[size] = std::strtol(item.c_str(), NULL, 10);
		_mSet.insert(intNumbers[size]); // nope
		// std::cout << "Position " << size << ": " << intNumbers[size] << std::endl;
		size++;
	} */
	std::vector<int>	intNumbers;
	while (ss >> item) {
		intNumbers.push_back(std::strtol(item.c_str(), NULL, 10));
	}
	size = intNumbers.size(); // needed?
	_hasStraggler = size % 2 == 0 ? false : true;

	std::vector<t_pair>	vChain;
	t_pair				tChain;

 // create double pointer array (struct) ***************************************
	for (size_t i = 0; i < (size - 1); i += 2) {
		tChain.min = std::min(intNumbers[i], intNumbers[i + 1]);
		tChain.max = std::max(intNumbers[i], intNumbers[i + 1]);
		vChain.push_back(tChain);

		std::cout << "vChain max:  " << vChain.back().max << std::endl;
		std::cout << "vChain min: " << vChain.back().min << std::endl;
	}
	std::cout << "Elements: " << vChain.size() << std::endl;
	if (_hasStraggler) {
		_straggler = intNumbers[size - 1];
		std::cout << "straggler: " << _straggler << std::endl;
	}
 // ****************************************************************************
	// delete[]intNumbers;
}

void	PmergeMe::mergeSort(int** inputArray) {
	std::cout << "straggler: " << _straggler << std::endl;
}