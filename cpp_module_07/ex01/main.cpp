#include "iter.hpp"

template<typename T>
void	print(T element) {
	std::cout << "print: " << element << std::endl;

	return ;
}

int main() {
	int a[5] = {1, 3, 5, 7, 9};

	::iter(a, 5, ::print);

	std::string str[] = {"Fee", "Fie", "Foe", "Foo"};
	::iter(str, 4, ::print);

	float   f[7] = {3.14f, 5.43f, 6, 87.23f, 12.5f, 11, 34.76f};
	::iter(f, 7, ::print);
	return 0;
}
