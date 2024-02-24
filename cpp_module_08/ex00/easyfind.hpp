#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <exception>
# include <algorithm>

class NotFound : public std::exception { 
	public: 
		virtual const char* what() const throw() { return "not found"; };
		};

template<typename T>
void	easyfind(T& c, int o) {
	typename T::const_iterator it;
	int	pos;

	it = std::find(c.begin(), c.end(), o);
	// c.begin() returns an iterator, so cast it to const_iterator (cbegin() since c++11)
	pos = std::distance<typename T::const_iterator>(c.begin(), it);
	
	if (it == c.end()) {
		std::cout << "Number " << o << " ";
		throw NotFound();
	}
	else{
		std::cout <<"Number " << *it;
		std::cout <<" found at position " << pos << std::endl;

	}
}

#endif /* EASYFIND_HPP */
