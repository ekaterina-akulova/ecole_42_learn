//
// Created by Екатерина Акулова on 24.10.2022.
//
#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    brain = new Brain;
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &dog) {
    type = dog.type;
    brain = new Brain;
    *(brain) = *(dog.brain);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog) {
    type = dog.type;
    *(brain) = *(dog.brain);
    std::cout << "A_Animal assigment operator called" << std::endl;
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}

void Dog::set_idea(int i, const std::string &idea) {
    (*brain)[i] = idea;
}

const std::string &Dog::get_idea(int i) const {
    return (*brain)[i];
}