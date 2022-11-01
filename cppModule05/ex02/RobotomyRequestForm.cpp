//
// Created by Екатерина Акулова on 28.10.2022.
//
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
        : Form(target, 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
        : Form(copy), target(copy.target){}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
    if (this != &copy) {
        target = copy.target;
    }
    return *this;
}

void RobotomyRequestForm::execute(const Bureacrat &executor) const {
    if (this->getIsSign() == false)
        throw "The Form is not signed!";
    if (executor.getGrade() > this->getGradeExec())
        throw Bureacrat::GradeTooLowExeption();

    std::srand(time(0));
    if (std::rand() % 2)
        std::cout << target << " robotization was successful" << std::endl;
    else
        std::cout << target << " robotization failed" << std::endl;
}