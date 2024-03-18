#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>
# include <sstream>
# include <vector>
# include <list>

class	PmergeMe
{
private:
	/* data */
	int**	_chain;

public:
	/* Orthodox canonical */
	PmergeMe();
	~PmergeMe();
	PmergeMe(PmergeMe const &copy);
	PmergeMe &operator=(const PmergeMe &rhs);

	PmergeMe(std::string const& numbers, size_t size);

};

#endif /* PMERGEME_HPP */
