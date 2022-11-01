//
// Created by Екатерина Акулова on 01.11.2022.
//
#include "Base.hpp"
static int random_num = std::rand() % 3;

Base::~Base(){}

Base * generate(void)
{
    switch (random_num) {
        {
            case 1:
                std::cout << "Generating A" << std::endl;
            return new A;
            case 2:
                std::cout << "Generating B" << std::endl;
            return new B;
            case 3:
                std::cout << "Generating C" << std::endl;
            return new C;
        }
    }
    return (NULL);
}

void identify(Base& p) {
    std::cout << "The actual type is: " ;
    switch (random_num) {
        case (1):
            std::cout << "A" << std::endl;
            break;
        case (2):
            std::cout << "B" << std::endl;
            break;
        case (3):
            std::cout << "C" << std::endl;
    }
    if (1 == 0)
        std::cout << &p << std::endl; //just to avoid make error not using p
}

void	identify(Base *p)
{
    identify(*p);
}
