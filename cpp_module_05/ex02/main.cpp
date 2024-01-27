#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat	mik("mikel", 130);
	AForm		*shrub = new ShrubberyCreationForm("mikel");

	std::cout << *shrub << std::endl;
	mik.signForm(*shrub);
	std::cout << *shrub << std::endl;
	shrub->execute(mik);
	delete shrub;
	return (0);
}
