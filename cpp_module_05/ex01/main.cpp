#include "Form.hpp"

int main() {
	try {
		Bureaucrat	mik("Mikel", 14);
		Bureaucrat	maik("Maik", 1);
		Form		fOne("Form 28C", 15, 5);
		Form		fCeo("Form 28C", 1, 1);
		Form		fCopy(fOne);
		Form		fEqual("fEqual", 10, 1);

		std::cout << fOne << std::endl;
		std::cout << fCopy << std::endl;
		mik.signForm(fOne);
		std::cout << fOne << std::endl;
		std::cout << fEqual << std::endl;
		fEqual = fOne;
		std::cout << fEqual << std::endl;
		mik.signForm(fCeo);
		// maik.signForm(fOne);
		// maik.incGrade();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
