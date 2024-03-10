#include "RPN.hpp"

RPN::RPN() {
	// std::cout << "RPN: Default Constructor Called" << std::endl;
}

RPN::~RPN() {
	// std::cout << "RPN: Destructor Called" << std::endl;
}

RPN::RPN(RPN const &copy) {
	// std::cout << "RPN: Copy Constructor Called" << std::endl;
	if (this != &copy)
		*this = copy;
}

RPN	&RPN::operator=(const RPN &rhs) {
	// std::cout << "RPN: Copy Assignment Operator Called" << std::endl;
	if (this != &rhs)
	{
		//	this->attributes = rhs.attributes;
		//	...
	}
	return (*this);
}

void TraverseString(std::string const &str, int N) 
{  
    // Traverse the string 
    for (int i = 0; i < N; i++) { 
  
        // Print current character 
        std::cout<< str[i]<< " "; 
    } 
      
} 

void	RPN::parseExpresion(std::string const& exp) {
	std::string	accepted = ".0123456789+-/* ";

	if (exp.find_first_not_of(accepted) != std::string::npos)
		throw NotAccepted(); 

	std::stringstream	ss(exp);
	std::string			word;

	while (ss >> word) {
		_pExp += word + ' ';
	}
	_pExp.erase(_pExp.length() - 1, 1);

	std::cout << "_pExp: [" << _pExp << "]" << std::endl;
}

/* float	RPN::compute(std::string const& exp) {
	std::string	item;

	for (size_t i = 0; i < exp.length(); i++) {
		
	}
} */