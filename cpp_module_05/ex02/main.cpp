#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	try {
		Bureaucrat	mik("mikel", 135);
		AForm		*shrub = new ShrubberyCreationForm("home");

		std::cout << *shrub << std::endl;
		mik.signForm(*shrub);
		std::cout << *shrub << std::endl;
		mik.executeForm(*shrub);
		delete shrub;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
