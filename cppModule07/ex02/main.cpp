//
// Created by Екатерина Акулова on 07.11.2022.
//
#include "Array.hpp"
int main()
{
    Array<float> a;
    a.getArray();
    a.size();

    std::cout << "---------------------" << std::endl;

    Array<int> b(4);
    b.setArray(1, 0);
    b.setArray(2, 1);
    b.setArray(3, 2);

    b.getArray();
    b.size();

    std::cout << "---------------------" << std::endl;

    Array<std::string> c(3);
    c.setArray("Hello ", 0);
    c.setArray("42 ", 1);
    c.setArray("Moskow", 2);

    c.getArray();
    c.size();

    std::cout << "---------------------" << std::endl;

    Array<std::string> d = c;
    d.setArray("Kazan", 2);

    d.getArray();
    d.size();

    std::cout << "---------------------" << std::endl;

    c.getArray();
    c.size();


//  system ("leaks array");
    return 0;
}