#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <exception>
# include <algorithm>

class NotFound : public std::exception { 
	public: 
		virtual const char* what() const throw() { return "Not found"; };
		};

template<typename T>
void	easyfind(T& c, int o) {
	typename T::iterator it;
	int	pos;

	it = std::find(c.begin(), c.end(), o);
	pos = std::distance(c.begin(), it);
	
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
