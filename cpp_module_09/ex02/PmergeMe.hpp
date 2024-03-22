#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <cstring>
# include <iostream>
# include <algorithm>
# include <sstream>
# include <limits>
# include <vector>
# include <list>
# include <set>

# define INTMAX std::numeric_limits<int>::max()

typedef struct s_pair {
	int	max;
	int	min;
} t_pair;

typedef std::vector<t_pair>::iterator	vIterator;
typedef std::list<t_pair>::iterator		lIterator;
typedef std::vector<int>				intVec;
typedef std::list<int>					intList;
typedef std::vector<t_pair>				pairVec;
typedef std::list<t_pair>				pairList;

class	PmergeMe
{
private:
	/* data */
	int		_straggler;
	intVec	_sortedVector;
	intList	_sortedList;

	intVec	getUnsortedNumbers(std::string const& numbers);
	pairVec	getPairedVector(intVec intN);
	void	getSortedVector(pairVec vChain);
	size_t	jacobsthal(size_t n);
public:
	/* Orthodox canonical */
	PmergeMe();
	~PmergeMe();
	PmergeMe(PmergeMe const &copy);
	PmergeMe &operator=(const PmergeMe &rhs);

	PmergeMe(std::string const& numbers);
	void	vecMergeSort(pairVec& inputVector);
	void	vecMerge(pairVec& inputVector,
					pairVec& left,
					pairVec& right);

};

std::ostream&	operator<<(std::ostream& os, intVec& elem);
std::ostream&	operator<<(std::ostream& os, pairVec& elem);
std::ostream&	operator<<(std::ostream& os, pairList& elem);

#endif /* PMERGEME_HPP */
