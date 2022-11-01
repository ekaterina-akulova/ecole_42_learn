//
// Created by Екатерина Акулова on 27.10.2022.
//

#ifndef BUREACRAT_HPP
#define BUREACRAT_HPP

#include <iostream>

class Exeption
{
protected:
    int num;
    std::string str;
public:
    Exeption()
    {
        std::cout <<"Default Constructor for Exeption called " << std::endl;
    };
    ~Exeption()
    {
        std::cout <<"Destructor for Exeption called " << std::endl;
    };

    virtual void display () = 0;
};

class Bureacrat {
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
    int grade;
public:
    Bureacrat();
    Bureacrat(const std::string &name, const int &grade);
    Bureacrat(Bureacrat &bureacrat): name(bureacrat.name), grade(bureacrat.grade){}
    Bureacrat &operator=(const Bureacrat &bureaucrat);
    ~Bureacrat();
    std::string getName(void) const;
    int getGrade(void) const;
    void increment_grade(void);
    void decrement_grade(void);
};

std::ostream &operator<<(std::ostream &out, const Bureacrat &bureacrat);

#endif //BUREACRAT_HPP