#include "Bureaucrat.hpp"
#include <iomanip>

int main() {
	try {
		Bureaucrat	mik("mikel", 150);
		Bureaucrat	emp("employee", 5);
		Bureaucrat	mikCopy(mik);

		
		std::cout << "Testing assignment operator: " << emp << std::endl;
		emp = mik;
		std::cout << "Testing assignment operator: " << emp << std::endl;
		std::cout << "Testing copy constructor: " << mikCopy << std::endl;
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
