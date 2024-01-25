#include "Bureaucrat.hpp"

int main() {
	Bureaucrat	mik("mikel", 1);

	std::cout << mik << std::endl;
	mik.incGrade();
	std::cout << mik << std::endl;
	mik.decGrade();
	std::cout << mik << std::endl;
	return (0);
}
