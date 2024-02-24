#ifndef SPAN_HPP
# define SPAN_HPP

# define NUMBERS 10000

# include <iostream>
# include <numeric>
# include <list>

// typedef std::list<int>::iterator Iterator;

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
		public: virtual const char* what() const throw();
	};
	class NotEnoughElements : public std::exception {
		public: virtual const char* what() const throw();
	};

	/* parametrized constructor */
	Span(unsigned int N);

	/* public methods */
	void			addNumber(int num);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();

	/* addNumber with a range of iterators */
	template <class InputIt>
	void addNumber(InputIt first, InputIt last) {
		while (first != last) {
			addNumber(*first++);
		}
	}
};

#endif /* SPAN_HPP */
