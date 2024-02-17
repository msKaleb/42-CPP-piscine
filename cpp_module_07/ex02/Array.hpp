#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>
class Array
{
private:
	/* data */
	unsigned int	_nElems;
	T				*_array;
public:

	Array<T>() : _nElems(0), _array(new T[0]) {};
	Array<T>(unsigned int elements) : _nElems(elements), _array(new T[elements]) {};
	~Array<T>() { delete[] this->_array; };
	Array<T>(Array<T> const& copy) : _nElems(copy._nElems), _array(new T[copy._nElems]) {
		for (unsigned int i = 0; i < _nElems; i++) {
			_array[i] = copy._array[i];
		}
	};
	Array<T>	&operator=(const Array& rhs) {
		if (this != &rhs) {
			this->~Array();
			new(this) Array<T>(rhs);
		}
	}
	class	OutOfBoundsException : public std::exception {
		public: virtual const char* what() const throw() { return "Out of bounds!"; };
	};

	T	const& operator[](const unsigned int index) const {
		if (index >= 0 && index < sizeof(this->_array) / sizeof(T))
			return this->_array[index];
		else
			throw OutOfBoundsException();
	}

	T&	operator[](const unsigned int index) {
		if (index >= 0 && index < this->_nElems)
			return this->_array[index];
		else
			throw OutOfBoundsException();
	}

	unsigned int	size() const { return this->_nElems; };

	/* T&	operator=(const int& rhs) {
		this->operator[]=
	} */
};
/* template<typename T>
std::ostream&	operator<<(std::ostream& o, T const& obj) {
	
} */

#endif /* ARRAY_HPP */
