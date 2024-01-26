#include "Form.hpp"

int main() {
	try {
		Bureaucrat	mik("mikel", 14);
		Form		fOne("28c", 15, 5);

		std::cout << fOne << std::endl;
		mik.signForm(fOne);
		fOne.beSigned(mik);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
