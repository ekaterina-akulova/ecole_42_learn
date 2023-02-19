//
// Created by Екатерина Акулова on 10.11.2022.
//

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>
# include <algorithm>

template <class T>	//	create a class template

class MutantStack : public std::stack<T> {
public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    MutantStack() {};
    ~MutantStack() {};
    //	Copy constructor
    MutantStack(const MutantStack<T> &object) : std::stack<T>(object) {
        //	or we can do it in a such way:
        //	this = this->std::stack<T>(object);
    };
    //	Copy assignment operator
    MutantStack const &operator=(MutantStack<T> &object) {
        this->std::stack<T>::operator=(object);
        return (*this);
    }
    iterator begin();
    iterator end();
};
#include "MutantStack.tpp"

#endif