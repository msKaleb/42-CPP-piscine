#include <list>
#include <cstdlib>
#include <iomanip>
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

/* { // second test
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

 // loop over to compare *******************************************************
	std::cout << "loop over to compare: " << std::endl;
	while (mIt != mIte)
		std::cout << "MutantStack: " << *mIt++ << std::endl;
	while (lIt != lite)
		std::cout << "list: " << *lIt++ << std::endl;
	while (dIt != dIte)
		std::cout << "deque: " << *dIt++ << std::endl;

 // testing copy constructor ***************************************************
	std::cout << "testing copy constructor: " << std::endl;
	MutantStack<int>	copy(mStack);

	copy.pop();
	std::cout << "Removed an item from copy" << std::endl;

	MutantStack<int>::const_iterator	cIt = copy.cbegin();
	MutantStack<int>::const_iterator	cIte = copy.cend();
	while (cIt != cIte)
		std::cout << "copy: " << *cIt++ << std::endl;

 // testing assignation operator ***********************************************
	std::cout << "testing assignation operator: " << std::endl;
 	MutantStack<int>	eq;

	eq = copy;

	std::cout << "Size: " << eq.size() << std::endl;
	eq.pop();
	std::cout << "Removed an item from eq" << std::endl;
	std::cout << "Size: " << eq.size() << std::endl;

	MutantStack<int>::reverse_iterator	eIt = eq.rbegin();
	MutantStack<int>::reverse_iterator	eIte = eq.rend();
	while (eIt != eIte)
		std::cout << "eq: " << *eIt++ << std::endl;

	return (0);
} */

{ // third test
	MutantStack<std::string>	mStack;
	MutantStack<float> 			mFloat;

 // push float numbers *********************************************************
	mFloat.push(34.5f);
	mFloat.push(65.8f);
	mFloat.push(16.1f);
	mFloat.push(98.54);

	// MutantStack<float>::iterator	fit = mFloat.begin();
	// MutantStack<float>::iterator	fite = mFloat.end();

	MutantStack<float>::const_iterator	fit = mFloat.cbegin();
	MutantStack<float>::const_iterator	fite = mFloat.cend();

	// MutantStack<float>::reverse_iterator	fit = mFloat.rbegin();
	// MutantStack<float>::reverse_iterator	fite = mFloat.rend();

	// MutantStack<float>::const_reverse_iterator	fit = mFloat.crbegin();
	// MutantStack<float>::const_reverse_iterator	fite = mFloat.crend();

	while (fit != fite)
		std::cout << *fit++ << std::endl;

	std::cout << std::setw(80) << std::setfill('-') << "" << std::endl;

 // push strings ***************************************************************
    mStack.push("1. Consectetur eiusmod elit est sunt culpa laboris cillum labore id deserunt");
    mStack.push("2. cupidatat culpa velit id. Duis excepteur consequat proident");
    mStack.push("3. incididunt et elit duis irure. Fugiat enim velit cillum labore");
    mStack.push("4. reprehenderit ea cillum id. Irure non fugiat eu occaecat");
    mStack.push("5. commodo sit commodo tempor. Mollit dolor reprehenderit nisi voluptate incididunt.");

	mStack.pop(); // remove the last element

 // different iterator types ************************************************
	// MutantStack<std::string>::const_reverse_iterator	it = mStack.crbegin();
	// MutantStack<std::string>::const_reverse_iterator	itEnd = mStack.crend();

	MutantStack<std::string>::reverse_iterator	it = mStack.rbegin();
	MutantStack<std::string>::reverse_iterator	itEnd = mStack.rend();

	// MutantStack<std::string>::const_iterator	it = mStack.cbegin();
	// MutantStack<std::string>::const_iterator	itEnd = mStack.cend();

	// MutantStack<std::string>::iterator	it = mStack.begin();
	// MutantStack<std::string>::iterator	itEnd = mStack.end();

	// ++it;
	// --itEnd;

	while (it != itEnd)
		std::cout << *it++ << std::endl;
}
}
