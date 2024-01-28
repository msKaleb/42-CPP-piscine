#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	try {
		Bureaucrat	employee("mikel", 43);
		AForm		*shrub = new ShrubberyCreationForm("home");
		AForm		*robot = new RobotomyRequestForm("paco");

		std::cout << *shrub << std::endl;
		employee.signForm(*shrub);
		employee.signForm(*robot);
		std::cout << *shrub << std::endl;
		employee.executeForm(*shrub);
		employee.executeForm(*robot);
		delete shrub;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
