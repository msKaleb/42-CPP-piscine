#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	AForm		*shrub = new ShrubberyCreationForm("home");
	AForm		*robot = new RobotomyRequestForm("paco");
	AForm		*pardon = new PresidentialPardonForm("bill");

	try {
		// instantiate employees
		Bureaucrat	employee("newbie", 137);
		Bureaucrat	manager("mikel", 40);
		Bureaucrat	ceo("maik", 1);


		// testing copy constructor and assignment operator
		{	
			PresidentialPardonForm	srcOne("test1");
			PresidentialPardonForm	srcTwo("test2");
			PresidentialPardonForm	cpy(srcOne);

			std::cout << "Testing copy before: \n" << cpy << std::endl;
			cpy = srcTwo;
			std::cout << "Testing copy after: \n" << cpy << std::endl;

		}

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
			// employee.signForm(*robot);
			// employee.executeForm(*robot);
			manager.signForm(*robot);
			manager.executeForm(*robot);

			delete robot;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			delete robot;
		}
		try {
			std::cout << *pardon << std::endl;
			ceo.signForm(*pardon);
			ceo.executeForm(*pardon);

			delete pardon;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			delete pardon;
		}
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		delete shrub;
		delete robot;
		delete pardon;
	}
	return (0);
}
