//
// Created by Екатерина Акулова on 27.10.2022.
//
#include "Bureacrat.hpp"

Bureacrat:: GradeTooHighExeption:: GradeTooHighExeption()
{
    std::cout << "Default Constructor for GradeTooHighExeption called" << std::endl;
}

Bureacrat:: GradeTooHighExeption:: ~GradeTooHighExeption()
{
    std::cout << "Destructor for GradeTooHighExeption called" << std::endl;
}

Bureacrat:: GradeTooHighExeption::GradeTooHighExeption(int num, std::string str)
{
    std::cout << "Constructor for GradeTooHighExeption called" << std::endl;
    this->num = num;
    this->str = str;
}

void Bureacrat::GradeTooHighExeption::display()
{
    std::cout << "Exeption - #" << num << ", " << str << std::endl;
}

Bureacrat:: GradeTooLowExeption:: GradeTooLowExeption()
{
    std::cout << "Default Constructor for GradeTooLowExeption called" << std::endl;
}

Bureacrat:: GradeTooLowExeption:: ~GradeTooLowExeption()
{
    std::cout << "Destructor for GradeTooLowExeption called" << std::endl;
}


Bureacrat:: GradeTooLowExeption:: GradeTooLowExeption(int num, std::string str)
{
    std::cout << "Constructor for GradeTooLowExeption called" << std::endl;
    this->num = num;
    this->str = str;
}

void Bureacrat::GradeTooLowExeption::display()
{
    std::cout << "Exeption - #" << num << ", " << str << std::endl;
}

Bureacrat::Bureacrat()
{
    std::cout << "Default Burecrat constructor called" << std::endl;
}

Bureacrat::Bureacrat(const std::string &name, const int &grade): name(name), grade(grade)
{
    std::cout << "Burecrat constructor called" << std::endl;
    try {
        if (grade <= 0)
            throw GradeTooHighExeption(0, "too high grade");
        if (grade >= 151)
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

void Bureacrat:: signForm(Form &form)
{
        form.beSigned(*this);
}

void Bureacrat::executeForm(const Form &form) {
        form.execute(*this);
}
Bureacrat &Bureacrat::operator=(const Bureacrat &bureaucrat)
{
    std::cout << "Copy Burecrat constructor called" << std::endl;
    const_cast<std::string &>(name) = bureaucrat.name;
    grade = bureaucrat.grade;
    return *this;
}

Bureacrat:: ~Bureacrat()
{
    std::cout << "Default Burecrat destructor called" << std::endl;
}

std::string Bureacrat:: getName(void) const
{
    return this->name;
}

int Bureacrat:: getGrade(void) const
{
    return this->grade;
}

void Bureacrat:: increment_grade(void)
{
    try {
        if (this->grade == 1)
            throw GradeTooHighExeption(0, "too high grade");
        grade--;
    }
    catch (GradeTooHighExeption &hexp)
    {
        hexp.display();

    }

}

void Bureacrat:: decrement_grade(void)
{
    try {
        if (this->grade == 150)
            throw GradeTooLowExeption(1, "too low grade");
        grade++;
    }
    catch (GradeTooLowExeption &lexp)
    {
        lexp.display();
    }
}

std::ostream &operator<<(std::ostream &out, const Bureacrat &bureacrat)
{
    out << bureacrat.getName()
    << ", grade = " << bureacrat.getGrade();
    return out;
}