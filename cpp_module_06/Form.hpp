#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class	Form
{
private:
	/* data */

public:
	/* Orthodox canonical */
	Form();
	~Form();
	Form(Form const &copy);
	Form &operator=(const Form &rhs);

};

#endif /* FORM_HPP */
