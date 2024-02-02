#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	try {
		// instantiate employees
		Bureaucrat	employee("CEO", 1);
		AForm*		emptyForm;
		Intern		mik;
		Intern		mik2;

		mik2 = mik;
		emptyForm = mik.makeForm("robotomy request", "Bender");
		std::cout << *emptyForm << std::endl;
		employee.signForm(*emptyForm);
		employee.executeForm(*emptyForm);
		delete emptyForm;

		emptyForm = mik2.makeForm("shrubbery creation", "my_home");
		employee.signForm(*emptyForm);
		employee.executeForm(*emptyForm);
		delete emptyForm;

		emptyForm = mik2.makeForm("presidential pardon", "my_home");
		employee.signForm(*emptyForm);
		employee.executeForm(*emptyForm);
		delete emptyForm;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
