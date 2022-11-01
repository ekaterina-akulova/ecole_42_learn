//
// Created by Екатерина Акулова on 31.10.2022.
//
#include "Form.hpp"

Form::Form() : name(""), sign(false), gradeSign(150), gradeExec(150) {}

Form::~Form() {}

//Form::Form(std::string name, int gradeSign, int gradeExec)
Form::Form(const std::string name,
           const int &gradeSign, const int &gradeExec)
        : name(name), sign(false),
          gradeSign(gradeSign), gradeExec(gradeExec) {
    if (gradeExec < 1 || gradeSign < 1)
        GradeTooHighException();
    if (gradeExec > 150 || gradeSign > 150)
        GradeTooLowException();
}

Form::Form(const Form &form)
        : name(form.name), sign(false),
          gradeSign(form.gradeSign), gradeExec(form.gradeExec){}

Form &Form::operator=(const Form &form) {
    if (this != &form) {
        const_cast<std::string &>(name) = form.name;
        const_cast<int &>(gradeExec) = form.gradeExec;
        const_cast<int &>(gradeSign) = form.gradeSign;
        sign = form.sign;
    }
    return *this;
}

std::string Form::getName() const { return name; }

int Form::getGradeExec() const { return gradeExec; }

int Form::getGradeSign() const { return gradeSign; }

bool Form::getSign() const { return sign; }

void Form::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > gradeSign)
        throw GradeTooLowException();
    sign = true;
}

const char *Form::GradeTooHighException::what() const throw() {
    return ("The Grade Form is too high!");
}

const char *Form::GradeTooLowException::what() const throw() {
    return ("The Grade Form is too low!");
}

std::ostream& operator<< (std::ostream &out, const Form &form)
{
    out	<< form.getName() << "	| signed: "
           << form.getSign() << "	| Grade to Sign: "
           << form.getGradeSign() << "	| Grade to Execute: "
           << form.getGradeExec();
    return (out);
}