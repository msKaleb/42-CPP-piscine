#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <numeric>
# include <list>

typedef std::list<int>::const_iterator Iterator;

class	Span
{
private:
	/* data */
	Span();
	unsigned int	_nMax;
	unsigned int	_nCurr;
	std::list<int>	_lInts;

public:
	/* Orthodox canonical */
	~Span();
	Span(Span const &copy);
	Span &operator=(const Span &rhs);

	/* exception classes */
	class MaxNumbers : public std::exception {
		public: virtual const char* what() const throw() {
			return "Max elements reached"; // in cpp??
		};
	};
	class NotEnoughElements : public std::exception {
		public: virtual const char* what() const throw() {
			return "Not enough elements"; // in cpp??
		};
	};

	/* parametrized constructor */
	Span(unsigned int N);

	/* public methods */
	void			addNumber(int num);
	std::list<int>	getSpan();
	unsigned int	shortestSpan();
	unsigned int	longestSpan();
};

#endif /* SPAN_HPP */
