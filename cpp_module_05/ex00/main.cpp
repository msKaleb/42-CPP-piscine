#include "Bureaucrat.hpp"
#include <iomanip>

int main() {
	try {
		Bureaucrat	mik("mikel", 150);

		for (int i = 0; i < 9; i++){
			std::cout << mik << std::endl;
			mik.incGrade();
		}
		std::cout << std::setfill('-') << std::setw(40)  << '\n';
		for (int i = 0; i < 10; i++){
			std::cout << mik << std::endl;
			mik.decGrade();
		}
		std::cout << mik << std::endl;
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
