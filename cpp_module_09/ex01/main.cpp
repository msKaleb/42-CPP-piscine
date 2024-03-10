#include "RPN.hpp"

int main(int argc, char* argv[]) {
	if (argc != 2)
		return 1;

	std::string	exp(argv[1]);
	RPN			rpn;

	// std::cout << exp << std::endl;
	try {
		rpn.parseExpresion(exp);
		// rpn.compute(exp);
	} catch (RPN::NotAccepted& e) {
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}
