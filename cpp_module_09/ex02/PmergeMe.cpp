#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _straggler(-1) {
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

PmergeMe::PmergeMe(std::string const& numbers) {
	std::stringstream	ss(numbers);
	std::string			item;
	std::vector<int>	intNumbers;	// make it member?
	std::vector<t_pair>	vChain;
	unsigned int		size = 0;

 // put into function **********************************************************
	while (ss >> item) {
		// todo: add a throw()
		char*	ending;
		long	lItem = std::strtol(item.c_str(), &ending, 10);
		if (*ending != 0) {
			std::cout << "ONLY NUMBERS!" << std::endl;
			return ;
		}
		else
			intNumbers.push_back(lItem);
	}

	size = intNumbers.size(); // needed?
	bool	hasStraggler = intNumbers.size() % 2 == 0 ? false : true;
	if (hasStraggler) {
		_straggler = intNumbers[size - 1];
		std::cout << "straggler: " << _straggler << std::endl;
	}
// *****************************************************************************


 // create double pointer array (struct) ***************************************
	for (size_t i = 0; i < (size - 1); i += 2) {
		t_pair	tChain;
		tChain.min = std::min(intNumbers[i], intNumbers[i + 1]);
		tChain.max = std::max(intNumbers[i], intNumbers[i + 1]);
		vChain.push_back(tChain);
	}

	std::cout << vChain << std::endl;
	vecMergeSort(vChain);
	std::cout << vChain << std::endl;
}

void	PmergeMe::vecMergeSort(std::vector<t_pair>& inputVector) {
	int	iLen = inputVector.size();
	if (iLen < 2)
		return ;

	int	iMid = iLen / 2;
	std::vector<t_pair>	left;
	std::vector<t_pair>	right;

 	for (int i = 0; i < iMid; i++)
		left.push_back(inputVector.at(i));
	for (int i = iMid; i < iLen; i++)
		right.push_back(inputVector.at(i));

	vecMergeSort(left);
	vecMergeSort(right);

	// std::cout << left << std::endl;
	// std::cout << right << std::endl;
	// std::cout << inputVector << std::endl;
	vecMerge(inputVector, left, right);
	// std::cout << inputVector << std::endl;
}

void	PmergeMe::vecMerge(std::vector<t_pair>& inputVector,
					std::vector<t_pair>& left,
					std::vector<t_pair>& right) {

	inputVector.clear();
	vIterator	lIt = left.begin(), lIte = left.end();
	vIterator	rIt = right.begin(), rIte = right.end();

	while (lIt != lIte && rIt != rIte) {
		if (lIt->max <= rIt->max) {
			inputVector.push_back(*lIt);
			lIt++;
		}
		else {
			inputVector.push_back(*rIt);
			rIt++;
		}
	}
	while (lIt != lIte)
		inputVector.push_back(*lIt++);
	while (rIt != rIte)
		inputVector.push_back(*rIt++);
}

std::ostream&	operator<<(std::ostream& os, std::vector<t_pair>& elem) {
	vIterator	it = elem.begin();
	vIterator	ite = elem.end();

	os << "Elements: " << elem.size() << std::endl;
	os << "-------------" << std::endl;
	while (it != ite) {
		os << "elem max:  " << it->max << std::endl;
		os << "elem min: " << it->min << std::endl;
		it++;
	}
	return os;
}

