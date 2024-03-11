#include "RPN.hpp"

int main(int argc, char* argv[]) {
	if (argc != 2)
		return 1;

	std::string	exp(argv[1]);
	RPN			rpn;

	try {
		rpn.parseExpresion(exp);
		std::cout << "RPN: " << rpn.compute() << std::endl;

		RPN	rpnCopy(rpn);

		std::cout << "RPN Copy: " << rpnCopy.compute() << std::endl;
	} catch (RPN::NotAccepted& e) {
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}
