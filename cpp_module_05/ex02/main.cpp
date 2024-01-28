#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	try {
		// instantiate employees
		Bureaucrat	employee("newbie", 137);
		Bureaucrat	manager("mikel", 40);
		Bureaucrat	ceo("maik", 1);

		AForm		*shrub = new ShrubberyCreationForm("home");
		AForm		*robot = new RobotomyRequestForm("paco");
		// testing copy constructor and assignment operator
		/* {	
			AForm		*copy(shrub);

			std::cout << "Testing copy: " << *copy << std::endl;
			*copy = *robot;
			std::cout << "Testing copy: " << *copy << std::endl;

			delete copy;
		} */

		try {
			std::cout << *shrub << std::endl;
			employee.signForm(*shrub);
			employee.executeForm(*shrub);

			delete shrub;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			delete shrub;
		}
		try {

			std::cout << *robot << std::endl;
			manager.signForm(*robot);
			/* employee.signForm(*robot);
			employee.executeForm(*robot); */
			manager.executeForm(*robot);

			delete robot;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			delete robot;
		}
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
