#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <deque>
# include <stack>

template<class T>
class MutantStack : public std::stack<T>
{
public:
	/* orthodox canonical */
	MutantStack<T>() : std::stack<T>() {}
	~MutantStack<T>() {};
	MutantStack<T>(MutantStack<T> const& copy) : std::stack<T>(copy) {}
	MutantStack<T> &operator=(const MutantStack<T> &rhs) {
		// c is a stack member object, which is the underlying container (deque by default)
		if (this != &rhs)
			this->c = rhs.c;
		return *this;
	}

 // iterators from deque, the default Containter for a stack *******************
	typedef typename std::deque<T>::const_reverse_iterator	const_reverse_iterator;
	typedef typename std::deque<T>::reverse_iterator		reverse_iterator;
	typedef typename std::deque<T>::const_iterator			const_iterator;
	typedef typename std::deque<T>::iterator				iterator;

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
