#include <cstring>
#include <cstdlib>
#include "Serializer.hpp"

int main(int argc, char* argv[]) {
	if (argc != 4) {
		std::cout << "enter three parameters: an int, a float and a string" << std::endl;
		return 1;
	}

	Data		*ptr = new Data();
	uintptr_t	serialized;
	Data		*deserialized;

	ptr->varOne = atoi(argv[1]);
	ptr->varTwo = atof(argv[2]);
	std::strcpy(ptr->varThree, argv[3]);

	serialized = Serializer::serialize(ptr);
	deserialized = Serializer::deserialize(serialized);

	std::cout << ptr->varOne << "|" << ptr->varTwo <<"|" << ptr->varThree << std::endl;
	std::cout << deserialized->varOne << "|" << deserialized->varTwo <<"|" << deserialized->varThree << std::endl;
	delete ptr;
	return (0);
}
