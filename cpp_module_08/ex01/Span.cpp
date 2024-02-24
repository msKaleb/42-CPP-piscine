#include "Span.hpp"

Span::Span() {
	// std::cout << "Span: Default Constructor Called" << std::endl;
}

Span::~Span() {
	// std::cout << "Span: Destructor Called" << std::endl;
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
		//	this->attributes = rhs.attributes;
		//	...
	}
	return (*this);
}

Span::Span(unsigned int	N) : _nMax(N), _nCurr(0) {}

void	Span::addNumber(int num) {
	if (_nCurr == _nMax)
		throw MaxNumbers();
	_lInts.push_front(num);
	_nCurr++;
	// std::cout << "Size: " << _lInts.size() << std::endl;
}

std::list<int>	Span::getSpan() {
	// first check if we can get a span (2 or more elements)
	if (_lInts.size() < 2)
		throw NotEnoughElements();
	std::list<int>	tmp(_nCurr);

	_lInts.sort();
	std::adjacent_difference(_lInts.begin(), _lInts.end(), tmp.begin());
	tmp.pop_front();
	tmp.sort();

	return tmp;
}

unsigned int	Span::shortestSpan() { return getSpan().front(); }

unsigned int	Span::longestSpan() { return getSpan().back(); }
