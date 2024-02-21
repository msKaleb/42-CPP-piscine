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
	typename T::const_iterator pos, dis;

	pos = std::find(c.begin(), c.end(), o);
	if (pos == c.end())
		throw NotFound();
	else
		std::cout << *pos << std::endl;
}

#endif /* EASYFIND_HPP */
