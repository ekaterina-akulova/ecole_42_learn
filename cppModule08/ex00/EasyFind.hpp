//
// Created by Екатерина Акулова on 09.11.2022.
//

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <iterator>
# include <stdexcept>
# include <list>
# include <vector>

template <typename T>
typename T::const_iterator	easyfind(T &cont, int n)
{
    typename T::const_iterator	it;

    if ((it = find(cont.begin(), cont.end(), n)) == cont.end())
        throw std::runtime_error("Element is not present in the container");
    return (it);
}

#endif