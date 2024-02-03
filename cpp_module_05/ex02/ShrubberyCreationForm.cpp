#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) :
	AForm("[Shrubbery Form " + target + "]", 145, 137) {
	// std::cout << "ShrubberyCreationForm: Default Constructor Called" << std::endl;
	// std::cout << ShrubberyCreationForm::_asciiTrees << std::endl;
	this->setTarget(target);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	// std::cout << "ShrubberyCreationForm: Destructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) :
	AForm(copy) {
	// std::cout << "ShrubberyCreationForm: Copy Constructor Called" << std::endl;
	if (this != &copy) {
		*this = copy;
		this->setTarget(copy.getTarget());
	}
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	std::cout << "ShrubberyCreationForm: Copy Assignment Operator Called" << std::endl;
	if (this != &rhs) {
		this->~ShrubberyCreationForm();
		new(this) ShrubberyCreationForm(rhs.getTarget());
	}
	return (*this);

	/* if (this != &rhs)
	{
		this->AForm::operator=(rhs);
		this->setTarget(rhs.getTarget());
	}
	return (*this); */
}

const char* ShrubberyCreationForm::OutputError::what() const throw() {
	return RED "Couldn't write to file" RESET;
}

void	ShrubberyCreationForm::executeDerived() const {
	if (!this->getExecuted())
		return ;
	std::string		fileName = this->getTarget() + "_shrubbery";
	std::ofstream	outFile;
	
	try {
		outFile.open(fileName.c_str());
		outFile << ShrubberyCreationForm::_asciiTrees << std::endl;
		outFile.close();
		std::cout << BLUE << fileName << " created!" << RESET << std::endl;
	}
	catch (std::exception &e) {
		throw ShrubberyCreationForm::OutputError();
	}
}

/* static string to store the ASCII trees */
std::string	ShrubberyCreationForm::_asciiTrees = \
"                                             \n" \
"               ,@@@@@@@,                   \n" \
"       ,,,.   ,@@@@@@/@@,  .oo8888o.       \n" \
"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o      \n" \
"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'     \n" \
"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'     \n" \
"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'      \n" \
"   `&%\\ ` /%&'    |.|        \\ '|8'        \n" \
"       |o|        | |         | |          \n" \
"       |.|        | |         | |          \n" \
"    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_  \n" \
"---------------------------------------------";
