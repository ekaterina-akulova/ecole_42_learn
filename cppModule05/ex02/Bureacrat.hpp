//
// Created by Екатерина Акулова on 27.10.2022.
//

#ifndef BUREACRAT_HPP
#define BUREACRAT_HPP

#include <iostream>
#include "Exeption.hpp"
#include "Form.hpp"

class Form;

class Bureacrat {
private:
    const std::string name;
    int grade;
public:
    class GradeTooHighExeption : public Exeption {
    public:
        GradeTooHighExeption();
        ~GradeTooHighExeption();
        GradeTooHighExeption(int num, std::string str);
        void display();
    };

    class GradeTooLowExeption : public Exeption
    {
    public:
        GradeTooLowExeption();
        ~GradeTooLowExeption();
        GradeTooLowExeption(int num, std::string str);
        void display ();
    };
    Bureacrat();
    Bureacrat(const std::string &name, const int &grade);
    Bureacrat(Bureacrat &bureacrat): name(bureacrat.name), grade(bureacrat.grade){}
    Bureacrat &operator=(const Bureacrat &bureaucrat);
    ~Bureacrat();
    std::string getName(void) const;
    int getGrade(void) const;
    void increment_grade(void);
    void decrement_grade(void);
    void	signForm(Form &form);
    void	executeForm(const Form &form);
};

std::ostream &operator<<(std::ostream &out, const Bureacrat &bureacrat);

#endif //BUREACRAT_HPP