//
// Created by Екатерина Акулова on 24.10.2022.
//
#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &cat) {
    type = cat.type;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat) {
    type = cat.type;
    std::cout << "Animal assigment operator called" << std::endl;
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}