#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate() {
	int	randomNumber;

	std::srand(std::time(NULL));
	randomNumber = std::rand() % 100;
	if (randomNumber < 33)
		return new A();
	else if (randomNumber >= 33 && randomNumber < 66)
		return new B();
	else
		return new C();
	return NULL;
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << p << ": A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << p << ": B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)	
		std::cout << p << ": C" << std::endl;
}

void	identify(Base& p) {
	try {
		A&	a = dynamic_cast<A&>(p);
		std::cout << &a << ": A" << std::endl;
	} catch (std::exception& e) {
		// std::cout << "Not A: " << e.what() << std::endl;
	}
	try {
		B&	b = dynamic_cast<B&>(p);
		std::cout << &b << ": B" << std::endl;
	} catch (std::exception& e) {
		// std::cout << "Not B: " << e.what() << std::endl;
	}
	try {
		C&	c = dynamic_cast<C&>(p);
		std::cout << &c << ": C" << std::endl;
	} catch (std::exception& e) {
		// std::cout << "Not C: " << e.what() << std::endl;
	}
}

int main() {
	Base*	ptr = generate();
	Base&	ref = *ptr;

	std::cout << "Testing identify(ptr): ";
	identify(ptr);
	std::cout << "Testing identify(ref): ";
	identify(ref);

	delete ptr;
	return (0);
}
