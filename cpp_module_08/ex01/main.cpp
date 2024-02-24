#include "Span.hpp"

int	main() {
	Span	sp(6);

try {
	sp.addNumber(-10);
	sp.addNumber(-13);
	sp.addNumber(0);
	sp.addNumber(119);
	/* sp.addNumber(-122);
	sp.addNumber(-123);
	sp.addNumber(-123);
	sp.addNumber(-123); */
} catch (Span::MaxNumbers& e) {
	std::cout << "Couldn't add more numbers. ";
	std::cout << e.what() << std::endl;
} catch (Span::NotEnoughElements& e) {
	std::cout << "Couldn't find the span. ";
	std::cout << e.what() << std::endl;
}
try {
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
} catch (Span::NotEnoughElements& e) {
	std::cout << "Couldn't find the span. ";
	std::cout << e.what() << std::endl;
}
}
