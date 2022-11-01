//
// Created by Екатерина Акулова on 28.10.2022.
//
#include "Form.hpp"
Form:: GradeTooHighExeption:: GradeTooHighExeption()
{
    std::cout << "Default Constructor for GradeTooHighExeption called" << std::endl;
}

Form:: GradeTooHighExeption:: ~GradeTooHighExeption()
{
    std::cout << "Destructor for GradeTooHighExeption called" << std::endl;
}

Form:: GradeTooHighExeption::GradeTooHighExeption(int num, std::string str)
{
    std::cout << "Constructor for GradeTooHighExeption called" << std::endl;
    this->num = num;
    this->str = str;
}

void Form::GradeTooHighExeption::display()
{
    std::cout << "Exeption - #" << num << ", " << str << std::endl;
}

Form:: GradeTooLowExeption:: GradeTooLowExeption()
{
    std::cout << "Default Constructor for GradeTooLowExeption called" << std::endl;
}

Form:: GradeTooLowExeption:: ~GradeTooLowExeption()
{
    std::cout << "Destructor for GradeTooLowExeption called" << std::endl;
}


Form:: GradeTooLowExeption:: GradeTooLowExeption(int num, std::string str)
{
    std::cout << "Constructor for GradeTooLowExeption called" << std::endl;
    this->num = num;
    this->str = str;
}

void Form::GradeTooLowExeption::display()
{
    std::cout << "Exeption - #" << num << ", " << str << std::endl;
}


Form::~Form()
{
    std::cout << "Default destructor for Form called" << std::endl;
}

Form::Form() : name(""),  isSigned(false), gradeSigned(1), gradeExec(1) {
    std::cout << "Default constructor for Form called" << std::endl;
}

Form::Form(const std::string name, const int &grade_signed, const int &grade_exec):  isSigned(false), gradeSigned(grade_signed), gradeExec(grade_exec) {
    std::cout << "Form constructor called" << std::endl;
    try {
        if (grade_signed <= 0 || grade_exec <= 0)
            throw GradeTooHighExeption(0, "too high grade");
        if (grade_signed >= 151 || grade_exec >= 151)
            throw GradeTooLowExeption(1, "too low grade");
    }
    catch (GradeTooHighExeption &hexp)
    {
        hexp.display();
    }
    catch (GradeTooLowExeption &lexp)
    {
        lexp.display();
    }
}

Form &Form::operator=(const Form &form) {
    const_cast<std::string &>(name) = form.name;
    const_cast<int &>(gradeExec) = form.gradeExec;
    const_cast<int &>(gradeSigned) = form.gradeSigned;
    isSigned = form.isSigned;
    return *this;
}

void Form::beSigned(Bureacrat &bureacrat) {
    try
    {
        if (bureacrat.getGrade() > gradeSigned)
            throw GradeTooLowExeption(1, "too low grade");
        else if (bureacrat.getGrade() < gradeSigned)
            throw GradeTooHighExeption(0, "too high exeption");
        isSigned = true;
        std::cout << bureacrat.getName() << " signed " << this->getName() << std::endl;
    }
    catch (GradeTooLowExeption &lexp)
    {
        lexp.display();
        std::cout << bureacrat.getName() << " couldn’t sign " << this->name << "because GradeTooLow" << std::endl;
    }
    catch (GradeTooHighExeption &hexp)
    {
        hexp.display();
        std::cout << bureacrat.getName() << " couldn’t sign " << this->name << "because GradeTooHigh" << std::endl;
    }
}


std::string Form::getName() const { return name; }

int Form::getGradeExec() const { return gradeExec; }

int Form::getGradeSign() const { return gradeSigned; }

bool Form::getIsSign() const { return isSigned; }

std::ostream& operator<< (std::ostream &out, const Form &form)
{
    out << "Name form: " << form.getName()
        << "\nSign: " << form.getIsSign()
        << "\nGrade to Sign: " << form.getGradeSign()
        << "\nGrade to Execute: " << form.getGradeExec();
    return (out);
}