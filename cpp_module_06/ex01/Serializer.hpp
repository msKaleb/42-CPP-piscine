#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>
# include "Data.h"

class	Serializer
{
private:
	/* data */
	Serializer();
	~Serializer();
	Serializer(Serializer const &copy);
	Serializer &operator=(const Serializer &rhs);

public:

	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};

#endif /* SERIALIZER_HPP */
