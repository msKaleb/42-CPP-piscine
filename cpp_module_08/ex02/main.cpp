#include <list>
#include <cstdlib>
#include "MutantStack.hpp"

int main() {
/* { // subject example
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	return 0;
} */
	MutantStack<int>	mStack;
	std::list<int>		lst;
	std::deque<int>		dc;

	for (int i = 0; i < 20; i++) {
		mStack.push(i * i);
		lst.push_back(i * i);
		dc.push_back(i * i);
	}

 // iterators ******************************************************************
	MutantStack<int>::iterator	mIt = mStack.begin();
	MutantStack<int>::iterator	mIte = mStack.end();
	std::list<int>::iterator	lIt = lst.begin();
	std::list<int>::iterator	lite = lst.end();
	std::deque<int>::iterator	dIt = dc.begin();
	std::deque<int>::iterator	dIte = dc.end();

	/* std::cout << "mIt: " << *mIt << std::endl;
	std::cout << "mIte: " << *mIte << std::endl;
	std::cout << "dIt: " << *dIt << std::endl;
	std::cout << "dIte: " << *dIte << std::endl;
	std::cout << "lIt: " << *lIt << std::endl;
	std::cout << "lite: " << *lite << std::endl; */

 // loop over to compare *******************************************************
	while (mIt != mIte)
		std::cout << "MutantStack: " << *mIt++ << std::endl;
	while (lIt != lite)
		std::cout << "list: " << *lIt++ << std::endl;
	while (dIt != dIte)
		std::cout << "deque: " << *dIt++ << std::endl;

 // testing copy constructor ***************************************************
	MutantStack<int>	copy(mStack);

	MutantStack<int>::const_iterator	cIt = copy.cbegin();
	MutantStack<int>::const_iterator	cIte = copy.cend();
	while (cIt != cIte)
		std::cout << "copy: " << *cIt++ << std::endl;

 // testing assignation operator ***********************************************
 	MutantStack<int>	eq;

	eq = copy;
	MutantStack<int>::reverse_iterator	eIt = eq.rbegin();
	MutantStack<int>::reverse_iterator	eIte = eq.rend();
	while (eIt != eIte)
		std::cout << "eq: " << *eIt++ << std::endl;

	return (0);
}
