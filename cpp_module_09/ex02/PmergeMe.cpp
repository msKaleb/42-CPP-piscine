#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _straggler(-1), _inserted(0) {
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
		this->_straggler = rhs._straggler;
		this->_inserted = rhs._inserted;
		this->_sortedVector = rhs._sortedVector;
		this->_sortedList = rhs._sortedList;
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
	intVec				intNumbers; // use deque??

	while (ss >> item) {
		char*	ending;
		long	lItem = std::strtol(item.c_str(), &ending, 10);
		if (lItem < 0 || *ending != 0 || lItem > INTMAX)
			throw NotInt();
		else
			intNumbers.push_back(lItem);
	}

	if (intNumbers.size() % 2 != 0) {
		_straggler = intNumbers.back();
		// std::cout << "straggler: " << _straggler << std::endl;
	}
	return intNumbers;
}

intVec	PmergeMe::getSortedVector() const { return this->_sortedVector; }

// create vector<t_pair> *******************************************************
pairVec	PmergeMe::makePairedVector(intVec intNumbers) {
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

void	PmergeMe::vecBinarySearch(int n, int T) {
	int	L = 0;
	int R = n;
	int	m;
	
	while (L <= R) {
		m = (L + R) / 2;
		if (_sortedVector.at(m) < T)
			L = m + 1;
		else if (_sortedVector.at(m) > T)
			R = m - 1;
		else {
			L = m;
			break ;
		}
	}
	_sortedVector.insert(_sortedVector.begin() + L, T);
	_inserted++;
}

// Ford-Johnson algorithm - insertion process **********************************
void	PmergeMe::sortVector(pairVec vChain) {
	vIterator	it = vChain.begin();
	vIterator	ite = vChain.end();

	_sortedVector.push_back(it->min);
	while (it != ite) {
		_sortedVector.push_back(it->max);
		it++;
	}

	size_t	jacobNumber = 3;
	int		jacobIndex = 3;
	int		jacobPos = 1;
	bool	loop = true;
	// int		cicles = 2;
	while (loop) {
		if (jacobNumber >= vChain.size()) {
			jacobNumber = vChain.size();
			loop = false;
		}
		for (int i = jacobNumber - 1; i >= jacobPos; i--) {
			vecBinarySearch(i + _inserted, vChain.at(i).min);
			// vecBinarySearch(std::pow(2, cicles) - 1, vChain.at(i).min);
		}
		jacobPos = jacobNumber;
		jacobNumber = jacobsthal(++jacobIndex);
		// cicles++;
	}
	if (_straggler >= 0)
		vecBinarySearch(_sortedVector.size(), _straggler);
}

// *****************************************************************************
// parametrized constructor
// *****************************************************************************
PmergeMe::PmergeMe(std::string const& numbers) : _straggler(-1), _inserted(0) {
	intVec	intNumbers = getUnsortedNumbers(numbers);
	pairVec	vChain = makePairedVector(intNumbers);

	vecMergeSort(vChain);	// sort the larger elements
	sortVector(vChain);		// insert pending elements into sorted vector


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
	size_t		index = 1;

	os << "Elements: " << elem.size() << std::endl;
	os << "-------------" << std::endl;
	while (it != ite) {
		os << "elem a" << index << ":  " << it->max << std::endl;
		os << "elem b" << index << ": " << it->min << std::endl;
		it++;
		index++;
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

	/* os << "Elements: " << elem.size() << std::endl;
	os << "-------------" << std::endl; */
	while (it != ite) {
		os << *it++ << " ";
	}
	os << std::endl;
	return os;
}

// operator<< overload for vector<int> const ************************************
std::ostream&	operator<<(std::ostream& os, intVec const& elem) {
	std::vector<int>::const_iterator	it = elem.begin();
	std::vector<int>::const_iterator	ite = elem.end();

	/* os << "Elements: " << elem.size() << std::endl;
	os << "-------------" << std::endl; */
	while (it != ite) {
		os << *it++ << " ";
	}
	os << std::endl;
	return os;
}
