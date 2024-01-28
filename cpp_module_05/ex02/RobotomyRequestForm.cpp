#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const target) :
	AForm("[Robotomy Form " + target + "]", 72, 45) {
	// std::cout << "RobotomyRequestForm: Default Constructor Called" << std::endl;
	this->setTarget(target);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	// std::cout << "RobotomyRequestForm: Destructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) :
	AForm(copy) {
	// std::cout << "RobotomyRequestForm: Copy Constructor Called" << std::endl;
	if (this != &copy)
		this->setTarget(copy.getTarget());
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	std::cout << "RobotomyRequestForm: Copy Assignment Operator Called" << std::endl;
	if (this != &rhs)
	{
		this->AForm::operator=(rhs);
		this->setTarget(rhs.getTarget());
	}
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	AForm::execute(executor);

	if (!this->getExecuted())
		return ;
	try {
	std::srand(std::time(nullptr));
	std::cout << YELLOW << "Some drilling noises..." << RESET << std::endl;
	if (std::rand() % 100 < 50)
		std::cout << GREEN << this->getTarget() << " has been robotomized" << RESET << std::endl;
	else
		std::cout << RED << this->getTarget() << " couldn't be robotomized" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
