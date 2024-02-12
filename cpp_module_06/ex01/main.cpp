#include "Serializer.hpp"
#include <cstring>

/**
 * @todo remove -Wno-unused
 * 
  */
int main() {
	Data		*ptr = new Data();
	uintptr_t	serialized;
	Data		*deserialized;

	ptr->varOne = 42;
	ptr->varTwo = 42.34f;
	std::strcpy(ptr->varThree, "Mikel");

	serialized = Serializer::serialize(ptr);
	deserialized = Serializer::deserialize(serialized);

	std::cout << ptr->varOne << "|" << ptr->varTwo <<"|" << ptr->varThree << std::endl;
	std::cout << deserialized->varOne << "|" << deserialized->varTwo <<"|" << deserialized->varThree << std::endl;
	return (0);
}
