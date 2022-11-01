//
// Created by Екатерина Акулова on 24.10.2022.
//
#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &animal) : type(animal.type) {
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &animal) {
    if (this != &animal) {
        type = animal.type;
    }
    std::cout << "Animal assigment operator called" << std::endl;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const {
    std::cout << "Animal make different sounds" << std::endl;
}

std::string Animal::getType() const { return type; }