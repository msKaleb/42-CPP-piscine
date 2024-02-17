#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array
{
private:
	/* data */
	T	_array;
public:

	Array<T>() : _array(new T[0]) {};
	Array<T>(size_t elements) : _array(new T[elements]) {};
	~Array<T>() { delete[] this->_array; };
};

#endif /* ARRAY_HPP */
