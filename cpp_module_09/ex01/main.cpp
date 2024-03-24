#include "RPN.hpp"

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "Input needed" << std::endl;
		return 1;
	}

	// get the whole expression
	std::string	exp = "";
	for (int i = 1; i < argc; i++) {
		exp += argv[i];
		exp += " ";
	}

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
