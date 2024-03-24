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
		this->_rpn = rhs._rpn;
		this->_pExp = rhs._pExp;
	}
	return (*this);
}

void	RPN::parseExpresion(std::string const& exp) {
	std::string	accepted = ".0123456789+-/* ";

	if (exp.find_first_not_of(accepted) != std::string::npos)
		throw NotAccepted(); 

	std::stringstream	ss(exp);
	std::string			word;

	while (ss >> word)
		_pExp += word + ' ';
	_pExp.erase(_pExp.length() - 1, 1);

	std::cout << "_pExp: [" << _pExp << "]" << std::endl;
}

float	RPN::compute(/* std::string const& exp */) {
	std::stringstream	ss(_pExp);
	std::string			item, operators = "+-*/";
	float				n1, n2;

	while (ss >> item) {
		// if (operators.find(item) != std::string::npos) {
		if (item.find_first_not_of("+-*/") == std::string::npos) {
			size_t pos = operators.find(item);
			if (_rpn.size() < 2 || item.length() != 1)
				throw NotAccepted();
			n1 = _rpn.top();
			_rpn.pop();
			n2 = _rpn.top();
			_rpn.pop();
			switch (pos)
			{
			case 0: // +
				_rpn.push(n2 + n1);
				break;
			case 1: // -
				_rpn.push(n2 - n1);
				break;
			case 2: // *
				_rpn.push(n2 * n1);
				break;
			case 3: // /
				_rpn.push(n2 / n1);
				break;
			default:
				break;
			}
		}
		else
			_rpn.push(std::strtof(item.c_str(), NULL)); // &ending
	}
	return _rpn.top();
}
