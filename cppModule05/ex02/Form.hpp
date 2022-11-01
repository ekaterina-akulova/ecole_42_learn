//
// Created by Екатерина Акулова on 28.10.2022.
//

#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureacrat.hpp"
#include "Exeption.hpp"


class Bureacrat;
class Exeption;

class Form
{
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
private:
    const std::string name;
    bool isSigned;
    const int gradeSigned;
    const int gradeExec;
public:
    Form();
    Form(const std::string name,
         const int &grade_signed, const int &grade_exec);
   // Form(const Form &form);
    ~Form();

    Form &operator=(const Form &form);

    std::string getName(void) const;
    int			getGradeExec() const;
    int			getGradeSign() const;
    bool		getIsSign() const;
    void	    beSigned(Bureacrat &bureacrat);
    virtual void execute(Bureacrat &executor) const;

};

std::ostream& operator<< (std::ostream &out, const Form &form);

#endif //FORM_HPP
