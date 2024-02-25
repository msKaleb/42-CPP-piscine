#include <list>
#include "MutantStack.hpp"

int main() {
	MutantStack<int>	mStack;
	std::list<int>		lst;
	std::deque<int>		dc;

	for (int i = 0; i < 20; i++) {
		mStack.push(i * i);
		lst.push_back(i * i);
		dc.push_back(i * i);
	}

	std::cout << mStack.top() << std::endl;
	MutantStack<int>::iterator	it = mStack.begin();
	MutantStack<int>::iterator	ite = mStack.end();
	std::list<int>::iterator	lit = lst.begin();
	std::list<int>::iterator	lite = lst.end();
	std::deque<int>::iterator	dit = dc.begin();
	std::deque<int>::iterator	dite = dc.end();

	std::cout << "it: " << *it << std::endl;
	std::cout << "ite: " << *ite << std::endl;
	std::cout << "dit: " << *dit << std::endl;
	std::cout << "dite: " << *dite << std::endl;
	std::cout << "lit: " << *lit << std::endl;
	std::cout << "lite: " << *lite << std::endl;

	while (it != ite)
		std::cout << "mStack: " << *it++ << std::endl;
	while (lit != lite)
		std::cout << "lst: " << *lit++ << std::endl;
	while (dit != dite)
		std::cout << "dc: " << *dit++ << std::endl;

	return (0);
}
