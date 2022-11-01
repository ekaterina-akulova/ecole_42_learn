//
// Created by Екатерина Акулова on 24.10.2022.
//

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << "Animal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal) : type(animal.type) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal) {
    if (this != &animal) {
        type = animal.type;
    }
    std::cout << "WrongAnimal assigment operator called" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "Animal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const { return type; }