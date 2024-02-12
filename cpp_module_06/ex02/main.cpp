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
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)	
		std::cout << "C" << std::endl;
}

void	identify(Base& p) {
	identify(&p);
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
