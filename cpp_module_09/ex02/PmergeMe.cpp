#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _straggler(-1) {
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
std::deque<int>	PmergeMe::getUnsortedNumbers(std::string const& numbers) {
	std::stringstream	ss(numbers);
	std::string			item;
	std::deque<int>		intNumbers; // use deque??

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
intList	PmergeMe::getSortedList() const { return this->_sortedList; }

// create list<t_pair> *********************************************************
pairList	PmergeMe::makePairedList(std::deque<int> intNumbers) {
	pairList	lChain;
	size_t		size = intNumbers.size();
	t_pair		tChain;

	for (size_t i = 0; i < (size - 1); i += 2) {
		tChain.min = std::min(intNumbers[i], intNumbers[i + 1]);
		tChain.max = std::max(intNumbers[i], intNumbers[i + 1]);
		lChain.push_back(tChain);
	}
	return lChain;
}

void	PmergeMe::listBinarySearch(int n, int T) {
	int	size = static_cast<int>(_sortedList.size());
	int	L = 0;
	int R = n;
	int	m;
	int	elem;

	if (R > size)
		R = size;

	while (L <= R) {
		m = (L + R) / 2;
		elem = at(_sortedList, m);
		if (elem < T)
			L = m + 1;
		else if (elem > T)
			R = m - 1;
		else {
			L = m;
			break ;
		}
	}
	intList::iterator	it = _sortedList.begin();
	while (int i = 0 != L) {
		it++;
		i++;
	}
	_sortedList.insert(it, T);
}

// Ford-Johnson algorithm - insertion process <list> ***************************
void	PmergeMe::sortList(pairList lChain) {
	lIterator	it = lChain.begin();
	lIterator	ite = lChain.end();

	_sortedList.push_back(it->min);
	while (it != ite) {
		_sortedList.push_back(it->max);
		it++;
	}

	size_t	jacobNumber = 3;
	int		jacobIndex = 3;
	int		jacobPos = 1;
	int		cycles = 2;
	bool	loop = true;
	while (loop) {
		if (jacobNumber >= lChain.size()) {
			jacobNumber = lChain.size();
			loop = false;
		}
		for (int i = jacobNumber - 1; i >= jacobPos; i--) {
			listBinarySearch(std::pow(2, cycles) - 1, at(lChain, i).min);
		}
		jacobPos = jacobNumber;
		jacobNumber = jacobsthal(++jacobIndex);
		cycles++;
	}
	if (_straggler >= 0)
		listBinarySearch(_sortedList.size(), _straggler);
}

// create vector<t_pair> *******************************************************
pairVec	PmergeMe::makePairedVector(std::deque<int> intNumbers) {
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
	int	size = static_cast<int>(_sortedVector.size());
	int	L = 0;
	int R = n;
	int	m;

	if (R > size)
		R = size;

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
	// _inserted++;
}

// Ford-Johnson algorithm - insertion process <vector> *************************
void	PmergeMe::sortVector(pairVec vChain) {
	vIterator	it = vChain.begin();
	vIterator	ite = vChain.end();

	_sortedVector.push_back(it->min);
	while (it != ite) {
		_sortedVector.push_back(it->max);
		it++;
	}

	size_t	jacobNumber = 3;
	size_t	jacobIndex = 3;
	size_t	jacobPos = 1;
	size_t	cycles = 2;
	bool	loop = true;
	while (loop) {
		if (jacobNumber >= vChain.size()) {
			jacobNumber = vChain.size();
			loop = false;
		}
		for (size_t i = jacobNumber - 1; i >= jacobPos; i--) {
			// vecBinarySearch(i + _inserted, vChain.at(i).min);
			/* if (i == jacobNumber - 1)
				std::cout << "cycle: " << cycles << " | " << std::pow(2, cycles) - 1  << " mine: " << i + _inserted << std::endl; */
			vecBinarySearch(std::pow(2, cycles) - 1, vChain.at(i).min);
		}
		jacobPos = jacobNumber;
		jacobNumber = jacobsthal(++jacobIndex);
		cycles++;
	}
	if (_straggler >= 0)
		vecBinarySearch(_sortedVector.size(), _straggler);
}

// *****************************************************************************
// parametrized constructor
// *****************************************************************************
PmergeMe::PmergeMe(std::string const& numbers) : _straggler(-1) {
	std::deque<int>		intNumbers = getUnsortedNumbers(numbers);
	pairVec				vChain = makePairedVector(intNumbers);
	pairList			lChain = makePairedList(intNumbers);

  // sorting process for vector ************************************************
	if (!vChain.empty()) {
		vecMergeSort(vChain);	// sort the larger elements
		sortVector(vChain);		// insert pending elements into sorted vector
	}
	else
		_sortedVector.push_back(std::strtol(numbers.c_str(), NULL, 10));

  // sorting process for list **************************************************
	if (!lChain.empty()) {
		listMergeSort(lChain);
		// std::cout << lChain << std::endl;
		sortList(lChain);
	}
	else
		_sortedList.push_back(std::strtol(numbers.c_str(), NULL, 10));
}

// merge-sort algorithm for larger elements (list) *****************************
void	PmergeMe::listMergeSort(pairList& inputList) {
	int	iLen = inputList.size();
	if (iLen < 2)
		return ;

	int	iMid = iLen / 2;
	pairList	left;
	pairList	right;

 	for (int i = 0; i < iMid; i++)
		left.push_back(at(inputList, i));
	for (int i = iMid; i < iLen; i++)
		right.push_back(at(inputList, i));

	// split in halves until one element is left
	listMergeSort(left);
	listMergeSort(right);

	// merge the halves and sort
	listMerge(inputList, left, right);
}

void	PmergeMe::listMerge(pairList& inputList,
					pairList& left,
					pairList& right) {
	inputList.clear();
	lIterator	lIt = left.begin(), lIte = left.end();
	lIterator	rIt = right.begin(), rIte = right.end();

	while (lIt != lIte && rIt != rIte) {
		if (lIt->max <= rIt->max) {
			inputList.push_back(*lIt);
			lIt++;
		}
		else {
			inputList.push_back(*rIt);
			rIt++;
		}
	}
	while (lIt != lIte)
		inputList.push_back(*lIt++);
	while (rIt != rIte)
		inputList.push_back(*rIt++);
}

int	PmergeMe::at(intList& inputList, int& index) {
	intList::iterator	it = inputList.begin();

	if (index > static_cast<int>(inputList.size()))	
		throw std::exception();
	while (int i = 0 != index) {
		it++;
		i++;
	}
	return *it;
}

t_pair	PmergeMe::at(pairList& inputList, int& index){
	lIterator	it = inputList.begin();
	// lIterator	ite = inputList.end();

	if (index > static_cast<int>(inputList.size()))	
		throw std::exception();
	while (int i = 0 != index) {
		it++;
		i++;
	}
	return *it;
}
// ***************************** merge-sort algorithm for larger elements (list)

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
// *************************** merge-sort algorithm for larger elements (vector)

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

	while (it != ite) {
		os << *it++ << " ";
	}
	return os;
}

// operator<< overload for vector<int> const ************************************
std::ostream&	operator<<(std::ostream& os, intVec const& elem) {
	std::vector<int>::const_iterator	it = elem.begin();
	std::vector<int>::const_iterator	ite = elem.end();

	while (it != ite) {
		os << *it++ << " ";
	}
	return os;
}

// operator<< overload for list<int> *******************************************
std::ostream&	operator<<(std::ostream& os, intList& elem) {
	std::list<int>::iterator	it = elem.begin();
	std::list<int>::iterator	ite = elem.end();

	while (it != ite) {
		os << *it++ << " ";
	}
	return os;
}

// operator<< overload for list<int> const **************************************
std::ostream&	operator<<(std::ostream& os, intList const& elem) {
	std::list<int>::const_iterator	it = elem.begin();
	std::list<int>::const_iterator	ite = elem.end();

	while (it != ite) {
		os << *it++ << " ";
	}
	return os;
}
