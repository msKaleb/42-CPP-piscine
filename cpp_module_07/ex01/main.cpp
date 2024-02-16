#include "iter.hpp"
// #include "../ex00/functions.hpp"

/**
 * @todo create an array of functions with return value
 */
int main() {
    int a[5] = {1, 3, 5, 7, 9};

    ::iter(a, 5, ::print);

    std::string str[3] = {"Mikel", "Soria", "Jiménez"};
    ::iter(str, 3, ::print);

    float   f[7] = {3.14f, 5.43f, 6, 87.23f, 12.5f, 11, 34.76f};
    ::iter(f, 7, ::print);
    return 0;
}
