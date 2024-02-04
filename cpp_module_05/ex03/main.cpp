#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	AForm*		emptyForm;
	try {
		// instantiate employees
		Bureaucrat	employee("CEO", 1);
		Intern		mik;
		Intern		mik2;

		mik2 = mik;
		emptyForm = mik.makeForm("robotomy request", "Bender");
		std::cout << *emptyForm << std::endl;
		employee.signForm(*emptyForm);
		employee.executeForm(*emptyForm);
		delete emptyForm;

		emptyForm = mik2.makeForm("shrubbery creation", "my_home");
		std::cout << *emptyForm << std::endl;
		employee.signForm(*emptyForm);
		employee.executeForm(*emptyForm);
		delete emptyForm;

		emptyForm = mik2.makeForm("presidential pardon", "Stan");
		std::cout << *emptyForm << std::endl;
		employee.signForm(*emptyForm);
		employee.executeForm(*emptyForm);
		delete emptyForm;
	} catch (Bureaucrat::BaseException &e) {
		std::cerr << e.what() << std::endl;
	} catch (AForm::BaseException &e) {
		std::cerr << e.what() << std::endl;
		delete emptyForm;
	} catch (Intern::makeFormException &e) {
		std::cerr << e.what() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		delete emptyForm;
	}
	return (0);
}
