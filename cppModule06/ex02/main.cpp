//
// Created by Екатерина Акулова on 01.11.2022.
//
#include "Base.hpp"

int	main(void)
{
    Base	*p = generate();

    if (!p)
        return EXIT_FAILURE;
    std::cout << "Using identify(Base *):" << std::endl;
    identify(p);
    std::cout << "Using identify(Base &):" << std::endl;
    identify(*p);
    delete p;
    return EXIT_SUCCESS;
}