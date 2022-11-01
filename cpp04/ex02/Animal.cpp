//
// Created by Екатерина Акулова on 24.10.2022.
//
#include "Animal.hpp"

A_Animal::A_Animal() {
    std::cout << "A_Animal default constructor called" << std::endl;
}

A_Animal::A_Animal(const A_Animal &A_Animal) : type(A_Animal.type) {
    std::cout << "A_Animal copy constructor called" << std::endl;
}

A_Animal &A_Animal::operator=(const A_Animal &A_Animal) {
    if (this != &A_Animal) {
        type = A_Animal.type;
    }
    std::cout << "A_Animal assigment operator called" << std::endl;
    return *this;
}

A_Animal::~A_Animal() {
    std::cout << "A_Animal destructor called" << std::endl;
}

std::string A_Animal::getType() const { return type; }