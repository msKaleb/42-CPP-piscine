#include "iter.hpp"

template<typename T>
void	print(T& element) {
	std::cout << element << std::endl;

	return ;
}

template<typename T>
int	capitalize(T& character) {
	character = toupper(character);
	return 0;
}

template<typename T>
void	increment(T& element) {
	element++;
}

void	incrementIt(int& num) {
	num++;
}

int main() {
	int a[5] = {1, 3, 5, 7, 9};
	::iter(a, 5, ::print);
	::iter(a, 5, ::increment<int>);
	std::cout << std::endl;
	::iter(a, 5, ::print);
	::iter(a, 5, ::incrementIt);
	std::cout << std::endl;
	::iter(a, 5, ::print);
	std::cout << std::endl;

	std::string str[] = {"Fee", "Fie", "Foe", "Foo"};
	::iter(str, 4, ::print);
	std::cout << std::endl;

	float   f[7] = {3.14f, 5.43f, 6, 87.23f, 12.5f, 11, 34.76f};
	::iter(f, 7, ::print);
	std::cout << std::endl;

	char charArray[] = {'a', 'b', 'c', 'd'};
	std::cout << charArray << std::endl;
	::iter( charArray, 4, ::capitalize<char>);
	std::cout << charArray << std::endl;
	return 0;
}
