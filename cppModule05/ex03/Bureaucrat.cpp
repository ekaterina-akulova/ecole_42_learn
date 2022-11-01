//
// Created by Екатерина Акулова on 31.10.2022.
//

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::~Bureaucrat() {}

//Bureaucrat::Bureaucrat(const std::string &name, int grade)
Bureaucrat::Bureaucrat(const std::string &name, const int &grade)
        : name(name), grade(grade) {
    if (grade > 150)
        throw GradeTooLowException();	//	making exception
    if (grade < 1)
        throw GradeTooHighException();	//	making exception
}
/*
Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) {
	(*this) = bureaucrat;
}
*/
Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
        : name(bureaucrat.name), grade(bureaucrat.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
    if (this != &bureaucrat) {
//		name = bureaucrat.name;	//	don't work because of const name
        const_cast<std::string &>(name) = bureaucrat.name;
        grade = bureaucrat.grade;
    }
    return *this;
}

std::string Bureaucrat::getName() const { return name; }

int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::upGrade() {
    if (grade == 1)
        throw GradeTooHighException();	//	making exception
    grade--;
}

void Bureaucrat::downGrade() {
    if (grade == 150)
        throw GradeTooLowException();	//	making exception
    grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Error! Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Error! Grade too low!";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
    out << bureaucrat.getName()
        << ", grade " << bureaucrat.getGrade();
    return out;
}

void Bureaucrat::signForm(Form &form) {
    try
    {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception &exc)
    {
        std::cerr	<< name << " couldn’t sign " << form.getName()
                     << " because " << exc.what() << std::endl;
    }
}

//void Bureaucrat::executeForm(Form const &form) {
void Bureaucrat::executeForm(const Form &form) {
    try {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    }
    catch (const char *str) {
        std::cerr	<< name << " couldn’t execute " << form.getName()
                     << " because " << str << std::endl;
    }
    catch (const std::exception &exc) {
        std::cerr << exc.what() << std::endl;
    }
}