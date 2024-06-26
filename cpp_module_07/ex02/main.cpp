#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
    Array<int>  i;
    Array<std::string> myStrings(5);
    myStrings[0] = "Consectetur eiusmod elit est sunt culpa laboris cillum labore id deserunt";
    myStrings[1] = "cupidatat culpa velit id. Duis excepteur consequat proident";
    myStrings[2] = "incididunt et elit duis irure. Fugiat enim velit cillum labore";
    myStrings[3] = "reprehenderit ea cillum id. Irure non fugiat eu occaecat";
    myStrings[4] = "commodo sit commodo tempor. Mollit dolor reprehenderit nisi voluptate incididunt.";
    std::cout << "Size of myStrings: " << myStrings.size() << std::endl;
    for (int i = 0; i < 5; i++)
        std::cout << myStrings[i] << std::endl;
    
    std::cout << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
