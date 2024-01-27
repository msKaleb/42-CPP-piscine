#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	AForm	*shrub = new ShrubberyCreationForm("mikel");

	std::cout << *shrub << std::endl;

	delete shrub;
	return (0);
}
