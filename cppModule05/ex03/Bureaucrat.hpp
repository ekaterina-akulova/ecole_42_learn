//
// Created by Екатерина Акулова on 31.10.2022.
//


#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat {
private:
//	std::string name;
    const	std::string name;
    int		grade;
public:
    Bureaucrat();
//	Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const std::string &name, const int &grade);
    Bureaucrat(const Bureaucrat &bureaucrat);
    ~Bureaucrat();

    Bureaucrat &operator=(const Bureaucrat &bureaucrat);

    std::string getName() const;
    int		getGrade() const;

    void	upGrade();
    void	downGrade();

    void	signForm(Form &form);
//	void	executeForm(Form const &form);
    void	executeForm(const Form &form);

    //	GradeTooHighException is a child of std::exception
    class	GradeTooHighException : public std::exception {
    public:
        //	here we override the function "what"
        virtual const char* what() const throw();
    };

    //	GradeTooLowException is a child of std::exception
    class GradeTooLowException : public std::exception {
    public:
        //	here we override the function "what"
        virtual const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif