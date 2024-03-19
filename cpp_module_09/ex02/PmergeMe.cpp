#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	// std::cout << "PmergeMe: Default Constructor Called" << std::endl;
}

PmergeMe::~PmergeMe() {
	// std::cout << "PmergeMe: Destructor Called" << std::endl;
	for (size_t i = 0; i < (_size / 2); i++) {
		delete[]_chain[i];
	}
	delete[]_chain;
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

PmergeMe::PmergeMe(std::string const& numbers, size_t size) : _size(size) {
	std::stringstream	ss(numbers);
	std::string			item;

	_hasStraggler = size % 2 == 0 ? false : true;

	int*	intNumbers = new int[size];
	size = 0;
	while (ss >> item) {
		intNumbers[size] = std::strtol(item.c_str(), NULL, 10);
		_mSet.insert(intNumbers[size]); // nope
		// std::cout << "Position " << size << ": " << intNumbers[size] << std::endl;
		size++;
	}

 // create double pointer array (in constructor?) ******************************
	_chain = new int*[size / 2]; // error when size = 0
	for (size_t i = 0; i < (size - 1); i += 2) {
		_chain[i] = new int[2];
		_chain[i][0] = std::min(intNumbers[i], intNumbers[i + 1]);
		_chain[i][1] = std::max(intNumbers[i], intNumbers[i + 1]);
		std::cout << "chain a " << i << ":  " << _chain[i][1] << std::endl;
		std::cout << "chain b " << i + 1 << ": " << _chain[i][0] << std::endl;
	}
	if (_hasStraggler) {
		_straggler = intNumbers[size - 1];
		std::cout << "straggler: " << _straggler << std::endl;
	}
 // ****************************************************************************
	delete[]intNumbers;
}