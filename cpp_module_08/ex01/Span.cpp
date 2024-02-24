#include "Span.hpp"

Span::Span() {
	// std::cout << "Span: Default Constructor Called" << std::endl;
}

Span::~Span() {
	// std::cout << "Span: Destructor Called" << std::endl;
	// _lInts.clear();
}

Span::Span(Span const &copy) {
	// std::cout << "Span: Copy Constructor Called" << std::endl;
	if (this != &copy)
		*this = copy;
}

Span	&Span::operator=(const Span &rhs) {
	// std::cout << "Span: Copy Assignment Operator Called" << std::endl;
	if (this != &rhs)
	{
		this->_lInts = std::list<int>(rhs._lInts);
		this->_nCurr = rhs._nCurr;
		this->_nMax = rhs._nMax;
	}
	return (*this);
}

/* ***** parametrized constructor ***** */
Span::Span(unsigned int	N) : _nMax(N), _nCurr(0) {}

void	Span::addNumber(int num) {
	if (_nCurr == _nMax)
		throw MaxNumbers();
	_lInts.push_front(num);
	_nCurr++;
}

/* ***** member functions ***** */
unsigned int	Span::shortestSpan() {
	// first check if we can get a span (2 or more elements)
	if (_lInts.size() < 2)
		throw NotEnoughElements();
	std::list<int>	tmp(_nCurr);

	_lInts.sort();
	std::adjacent_difference(_lInts.begin(), _lInts.end(), tmp.begin());
	tmp.pop_front();
	tmp.sort();

	return tmp.front();
}

unsigned int	Span::longestSpan() {
	// first check if we can get a span (2 or more elements)
	if (_lInts.size() < 2)
		throw NotEnoughElements();
	std::list<int>	maxMin;
	std::list<int>	tmp(2);

	_lInts.sort();
	maxMin.push_back(_lInts.front());
	maxMin.push_back(_lInts.back());
	std::adjacent_difference(maxMin.begin(), maxMin.end(), tmp.begin());

	return tmp.back();
}

/* ***** exceptions ***** */
const char*	Span::MaxNumbers::what() const throw() {
	return "Couldn't add number. Maximum number of elements reached";
}

const char*	Span::NotEnoughElements::what() const throw() {
	return "Not enough elements. Add at least two elements to the list";
}