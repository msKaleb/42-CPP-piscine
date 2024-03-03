#include "Span.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>

void	FillArray(int* array) {
	std::srand(std::time(NULL));

	for(int i = 0; i < NUMBERS; i++) {
		array[i] = std::rand();
	}
}

int	main() {
/* { // subject main example
	Span	sp(5);

	try	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		// sp.addNumber(33); // this throws an exception
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
} */
{ // another testing scope
	// the Span class object
	Span	sp(NUMBERS);

	// create and fill an array with random numbers
	int	array[NUMBERS];
	FillArray(array);

	// create a vector container and call its constructor with the array data:
	// vector(InputIt first, InputIt last, const Allocator& alloc = Allocator());
	std::vector<int>	vec(array, array + sizeof(array) / sizeof(array[0]));
	std::cout << "Number of items in vector: " <<vec.size() << std::endl;

	try {
		// use the overridden version of addNumber() using a range of iterators
		sp.addNumber(vec.begin(), vec.end());
		// sp.addNumber(array + 50, array + 4000);
	} catch (Span::MaxNumbers& e) {
		std::cout << "Couldn't add more numbers. ";
		std::cout << e.what() << std::endl;
	} catch (Span::NotEnoughElements& e) {
		std::cout << "Couldn't find the span. ";
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "Min span: " << sp.shortestSpan() << std::endl;
		std::cout << "Max span: " << sp.longestSpan() << std::endl;
	} catch (Span::NotEnoughElements& e) {
		std::cout << "Couldn't find the span. ";
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}
} // main
