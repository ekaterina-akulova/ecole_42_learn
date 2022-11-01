//
// Created by Екатерина Акулова on 24.10.2022.
//

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain default constructor called" << std::endl;
    for (int i = 0; i < max_num; i++)
        set_idea(i, " idea");
}

Brain::Brain(const Brain &brain) {
    *this = brain;
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < max_num; i++)
        set_idea(i, brain.get_idea(i));
}

Brain &Brain::operator=(const Brain &brain) {
    std::cout << "Brain assigment operator called" << std::endl;
    for (int i = 0; i < max_num; i++)
        set_idea(i, brain.get_idea(i));
    return *this;
}

std::string &Brain::operator[](int i) {
    return ideas[i];
}

void Brain::set_idea(int i, const std::string &idea) {
    ideas[i] = idea;
}

const std::string &Brain::get_idea(int i) const {
    return ideas[i];
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}