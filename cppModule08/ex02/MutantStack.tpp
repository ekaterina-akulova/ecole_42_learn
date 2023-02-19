//
// Created by Екатерина Акулова on 10.11.2022.
//
#include "MutantStack.hpp"

template<class T>
//typename std::stack<T>::container_type::iterator MutantStack<T>::begin() {
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return this->c.begin();
}

template<class T>
//typename std::stack<T>::container_type::iterator MutantStack<T>::end() {
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return this->c.end();
}