#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>
# include <sstream>
# include <vector>
# include <list>
# include <set>

class	PmergeMe
{
private:
	/* data */
	int**	_chain;
	int		_straggler;
	size_t	_size;
	bool	_hasStraggler;
	std::multiset<int>	_mSet;

public:
	/* Orthodox canonical */
	PmergeMe();
	~PmergeMe();
	PmergeMe(PmergeMe const &copy);
	PmergeMe &operator=(const PmergeMe &rhs);

	PmergeMe(std::string const& numbers, size_t size);

};

#endif /* PMERGEME_HPP */
