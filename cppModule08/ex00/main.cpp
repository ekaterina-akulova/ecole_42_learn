#include "EasyFind.hpp"

int		main()
{
    std::cout << "----------LISTS----------\n";
    std::list<int>		lst;

    lst.push_back(55);
    lst.push_back(0);
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(38);
    lst.push_back(9);
    lst.push_back(2);
    std::list<int>::const_iterator	it = easyfind(lst, 2);
    std::cout << *it << '\n';
    try
    {
        it = easyfind(lst, 10);
        std::cout << *it << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        it = easyfind(lst, 38);
        std::cout << *it << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "---------VECTORS---------\n";
    std::vector<int>	v(2, 100);

    v.push_back(99);
    std::vector<int>::const_iterator	it2 = easyfind(v, 99);
    std::cout << *it2 << '\n';
    try
    {
        it2 = easyfind(v, 10);
        std::cout << *it2 << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        it2 = easyfind(v, 100);
        std::cout << *it2 << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}