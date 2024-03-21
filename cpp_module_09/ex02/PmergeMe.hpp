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

typedef std::vector<t_pair>::iterator vIterator;

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

	PmergeMe(std::string const& numbers);
	void	vecMergeSort(std::vector<t_pair>& inputVector);
	void	vecMerge(std::vector<t_pair>& inputVector,
					std::vector<t_pair>& left,
					std::vector<t_pair>& right);

};

std::ostream&	operator<<(std::ostream& os, std::vector<t_pair>& elem);
#endif /* PMERGEME_HPP */
