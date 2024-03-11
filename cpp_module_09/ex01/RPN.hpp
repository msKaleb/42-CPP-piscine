#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <cstdlib>
# include <sstream>

class	RPN
{
private:
	/* data */
	std::stack<float>	_rpn;
	std::string			_pExp;

public:
	/* Orthodox canonical */
	RPN();
	~RPN();
	RPN(RPN const &copy);
	RPN &operator=(const RPN &rhs);

	class NotAccepted : public std::exception {
		public: virtual const char* what() const throw() { return "Error."; }
	};

	void	parseExpresion(std::string const& exp);
	float	compute(/* std::string const& exp */);

};

#endif /* RPN_HPP */
