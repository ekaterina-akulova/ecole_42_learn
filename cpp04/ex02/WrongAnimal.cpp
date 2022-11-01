//
// Created by Екатерина Акулова on 24.10.2022.
//

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << "A_Animal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &A_Animal) : type(A_Animal.type) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &A_Animal) {
    if (this != &A_Animal) {
        type = A_Animal.type;
    }
    std::cout << "WrongAnimal assigment operator called" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "A_Animal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const { return type; }