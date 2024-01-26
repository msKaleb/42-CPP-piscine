#include "bException.hpp"

const char* bException::what() const throw() {
	return "Invalid grade number";
}
