#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <cstring>
# include <iostream>
# include <algorithm>
# include <cmath>
# include <sstream>
# include <limits>
# include <vector>
# include <list>
# include <deque>
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
	// make it private so that only can be instantiated with args (change??)
	PmergeMe();

	int		_straggler;		// if the chain is odd, store it
	// int		_inserted;		// counter for inserted pending elements
	intVec	_sortedVector;	// sorted chain (vector)
	intList	_sortedList;	// sorted chain (list)

	// First create an array with all the numbers passed as argument
	std::deque<int>	getUnsortedNumbers(std::string const& numbers);

	// make a min-max paired arrays
	pairVec		makePairedVector(std::deque<int> intN);
	pairList	makePairedList(std::deque<int> intN);

	// return the Jacobsthal number at index n
	size_t	jacobsthal(size_t n);

	void	vecBinarySearch(int n, int T);
	void	listBinarySearch(int n, int T);

	// set of functions for the paired vector<t_pair>
	void	sortVector(pairVec vChain);
	void	vecMergeSort(pairVec& inputVector);
	void	vecMerge(pairVec& inputVector,
					pairVec& left,
					pairVec& right);

	// set of functions for the paired list<t_pair>
	t_pair	at(pairList& inputList, int& index);
	int		at(intList& inputList, int& index);
	void	sortList(pairList vChain);
	void	listMergeSort(pairList& inputList);
	void	listMerge(pairList& inputList,
					pairList& left,
					pairList& right);

public:
	/* Orthodox canonical */
	~PmergeMe();
	PmergeMe(PmergeMe const &copy);
	PmergeMe &operator=(const PmergeMe &rhs);

	PmergeMe(std::string const& numbers);
	intVec	getSortedVector() const;
	intList	getSortedList() const;

	class NotInt : public std::exception {
		public: virtual const char* what() const throw() { return "Only positive integers"; }
	};
};

std::ostream&	operator<<(std::ostream& os, intVec& elem);
std::ostream&	operator<<(std::ostream& os, intVec const& elem);
std::ostream&	operator<<(std::ostream& os, intList& elem);
std::ostream&	operator<<(std::ostream& os, intList const& elem);
std::ostream&	operator<<(std::ostream& os, pairVec& elem);
std::ostream&	operator<<(std::ostream& os, pairList& elem);


#endif /* PMERGEME_HPP */
