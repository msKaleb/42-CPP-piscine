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
	MutantStack<T, Container>(MutantStack<T, Container> const& copy) : std::stack<T>(copy) {/*  *this = copy;  */}
	MutantStack<T, Container> &operator=(const MutantStack<T, Container> &rhs) {
		if (this != &rhs)
			this->c = rhs.c;
		return *this;
	}

	typedef typename Container::const_reverse_iterator	const_reverse_iterator;
	typedef typename Container::reverse_iterator		reverse_iterator;
	typedef typename Container::const_iterator			const_iterator;
	typedef typename Container::iterator				iterator;

	iterator				begin() 		{ return this->c.begin(); }
	iterator				end() 			{ return this->c.end(); }
	const_iterator			cbegin() const 	{ return this->c.begin(); }
	const_iterator			cend() const 	{ return this->c.end(); }
	reverse_iterator		rbegin() 		{ return this->c.rbegin(); }
	reverse_iterator		rend() 			{ return this->c.rend(); }
	const_reverse_iterator	crbegin() const	{ return this->c.rbegin(); }
	const_reverse_iterator	crend() const	{ return this->c.rend(); }
};

#endif /* MUTANTSTACK_HPP */
