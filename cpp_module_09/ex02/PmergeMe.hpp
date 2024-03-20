#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <cstring>
# include <iostream>
# include <algorithm>
# include <sstream>
# include <vector>
# include <list>
# include <set>

typedef struct s_pair
{
	int	max;
	int	min;
}			t_pair;

class	PmergeMe
{
private:
	/* data */
	int**	_chain;
	t_pair	*_tChain;
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
	void	mergeSort(int** inputArray);

};

#endif /* PMERGEME_HPP */
