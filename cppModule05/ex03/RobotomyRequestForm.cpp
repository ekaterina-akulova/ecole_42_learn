//
// Created by Екатерина Акулова on 31.10.2022.
//
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
        : Form(target, 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
        : Form(copy), target(copy.target)
{
//	*this = copy;	//	not necessary
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
    if (this != &copy) {
        target = copy.target;
    }
    return *this;
}

//void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    if (this->getSign() == false)
        throw "The Form is not signed!";
    if (executor.getGrade() > this->getGradeExec())
        throw Bureaucrat::GradeTooLowException();

    std::srand(time(0));
//	std::cout << std::rand() << std::endl;
    if (std::rand() % 2)
        std::cout << target << " robotization was successful" << std::endl;
    else
        std::cout << target << " robotization failed" << std::endl;
}