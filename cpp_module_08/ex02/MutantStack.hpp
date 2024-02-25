#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <deque>
# include <stack>

template<
	class T,
	class Container = std::deque<T>
>
class MutantStack : public std::stack<T>
{
private:
	/* data */

public:
	/* orthodox canonical */
	MutantStack<T, Container>() : std::stack<T>() {}
	~MutantStack<T, Container>() {};
	MutantStack<T, Container>(MutantStack<T, Container> const& copy) { *this = copy; }
	MutantStack<T, Container> &operator=(const MutantStack<T, Container> &rhs) {
		if (this != &rhs)
			this->c = rhs->c;
		return *this;
	}

	typedef typename Container::iterator iterator;
	iterator	begin() { return this->c.begin(); }
	iterator	end() { return this->c.end(); }
};

#endif /* MUTANTSTACK_HPP */
