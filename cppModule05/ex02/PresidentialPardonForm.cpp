//
// Created by Екатерина Акулова on 28.10.2022.
//
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
        : Form(target, 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
        : Form(copy), target(copy.target){}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
    if (this != &copy) {
        target = copy.target;
    }
    return *this;
}

void PresidentialPardonForm::execute(const Bureacrat &executor) const {
    if (this->getIsSign() == false)
        throw "The Form is not signed!";
    if (executor.getGrade() > this->getGradeExec()) {
        throw Bureacrat::GradeTooLowExeption();
    }

    std::cout << target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}