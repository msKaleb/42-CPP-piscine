#include "Form.hpp"

int main() {
	try {
		Form	fOne("28c", 15, 5);

		std::cout << fOne << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
