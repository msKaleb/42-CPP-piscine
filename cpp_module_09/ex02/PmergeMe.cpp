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

// get jacobsthal sequence *****************************************************
size_t	PmergeMe::jacobsthal(size_t n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return jacobsthal(n - 1) + 2 * (jacobsthal(n - 2));
}

// get the list of numbers from argv *******************************************
intVec	PmergeMe::getUnsortedNumbers(std::string const& numbers) {
	std::stringstream	ss(numbers);
	std::string			item;
	intVec				intNumbers;
	size_t				size;

	while (ss >> item) {
		// todo: add a throw()
		char*	ending;
		long	lItem = std::strtol(item.c_str(), &ending, 10);
		if (*ending != 0 || lItem > INTMAX) {
			std::cout << "ONLY INT NUMBERS!" << std::endl;
			intNumbers.clear(); // change with exception
			return intNumbers;  // change with exception
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
	return intNumbers;
}

// create vector<t_pair> *******************************************************
pairVec	PmergeMe::getPairedVector(intVec intNumbers) {
	pairVec	vChain;
	size_t	size = intNumbers.size();
	t_pair	tChain;

	for (size_t i = 0; i < (size - 1); i += 2) {
		tChain.min = std::min(intNumbers[i], intNumbers[i + 1]);
		tChain.max = std::max(intNumbers[i], intNumbers[i + 1]);
		vChain.push_back(tChain);
	}
	return vChain;
}

// Ford-Johnson algorithm - insertion process **********************************
void	PmergeMe::getSortedVector(pairVec vChain) {
	vIterator	it = vChain.begin();
	vIterator	ite = vChain.end();

	_sortedVector.push_back(it->min);
	while (it != ite) {
		_sortedVector.push_back(it->max);
		it++;
	}

	int		jacobIndex = 3;
	int		jacobPos = 1;
	bool	loop = true;
	while (loop) {
		size_t	jacobNumber = jacobsthal(jacobIndex);
		if (jacobNumber >= vChain.size()) {
			jacobNumber = vChain.size();
			loop = false;
		}

		for (int i = jacobNumber - 1; i >= jacobPos; i--) {
			std::cout << vChain.at(i).min << " ";
		}
		jacobPos = jacobIndex;
		jacobIndex++;
		jacobNumber = jacobsthal(jacobIndex);
	}
	std::cout << std::endl;
	std::cout << _sortedVector << std::endl;
}

// parametrized constructor ****************************************************
PmergeMe::PmergeMe(std::string const& numbers) {
	intVec	intNumbers = getUnsortedNumbers(numbers);
	pairVec	vChain = getPairedVector(intNumbers);

	std::cout << vChain << std::endl;
	vecMergeSort(vChain);
	std::cout << vChain << std::endl;
	getSortedVector(vChain);
}

// merge-sort algorithm for larger elements (vector) ***************************
void	PmergeMe::vecMergeSort(pairVec& inputVector) {
	int	iLen = inputVector.size();
	if (iLen < 2)
		return ;

	int	iMid = iLen / 2;
	pairVec	left;
	pairVec	right;

 	for (int i = 0; i < iMid; i++)
		left.push_back(inputVector.at(i));
	for (int i = iMid; i < iLen; i++)
		right.push_back(inputVector.at(i));

	// split in halves until one element is left
	vecMergeSort(left);
	vecMergeSort(right);

	// merge the halves and sort
	vecMerge(inputVector, left, right);
}

void	PmergeMe::vecMerge(pairVec& inputVector,
					pairVec& left,
					pairVec& right) {

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
// *****************************************************************************

// operator<< overload for vector<t_pair> **************************************
std::ostream&	operator<<(std::ostream& os, pairVec& elem) {
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

// operator<< overload for list<t_pair> ****************************************
std::ostream&	operator<<(std::ostream& os, pairList& elem) {
	lIterator	it = elem.begin();
	lIterator	ite = elem.end();

	os << "Elements: " << elem.size() << std::endl;
	os << "-------------" << std::endl;
	while (it != ite) {
		os << "elem max:  " << it->max << std::endl;
		os << "elem min: " << it->min << std::endl;
		it++;
	}
	return os;
}

// operator<< overload for vector<int> *****************************************
std::ostream&	operator<<(std::ostream& os, intVec& elem) {
	std::vector<int>::iterator	it = elem.begin();
	std::vector<int>::iterator	ite = elem.end();

	os << "Elements: " << elem.size() << std::endl;
	os << "-------------" << std::endl;
	while (it != ite) {
		os << *it++ << " ";
	}
	os << std::endl;
	return os;
}
