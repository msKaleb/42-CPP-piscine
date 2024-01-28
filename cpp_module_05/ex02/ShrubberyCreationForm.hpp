#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"

class	ShrubberyCreationForm : public AForm
{
private:
	/* data */
	static std::string	_asciiTrees;

	ShrubberyCreationForm();
public:
	/* exceptions */
	class	OutputError : public std::exception {
		virtual const char *what() const throw();
	};

	/* Orthodox canonical */
	ShrubberyCreationForm(std::string const target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const &copy);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

	virtual void	execute(Bureaucrat const &executor) const;
};

#endif /* SHRUBBERYCREATIONFORM_HPP */
