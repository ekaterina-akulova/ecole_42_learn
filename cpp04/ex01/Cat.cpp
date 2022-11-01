//
// Created by Екатерина Акулова on 24.10.2022.
//
#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    brain = new Brain;
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &cat) {
    type = cat.type;
    brain = new Brain;
    *(brain) = *(cat.brain); //deep copy;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat) {
    type = cat.type;
    *(brain) = *(cat.brain);
    std::cout << "Animal assigment operator called" << std::endl;
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete brain;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}
void Cat::set_idea(int i, const std::string &idea) {
    (*brain)[i] = idea;
}

const std::string &Cat::get_idea(int i) const {
    return (*brain)[i];
}