//
// Created by Екатерина Акулова on 31.10.2022.
//
#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
    const std::string	name;
    bool				sign;
    const int			gradeSign;
    const int 			gradeExec;
public:
    Form();
//	Form(std::string name, int gradeSign, int gradeExec);
    Form(const std::string name,
         const int &gradeSign, const int &gradeExec);
    Form(const Form &form);
    virtual ~Form();	//	so other forms can self-destruct

    Form &operator=(const Form &form);

    std::string getName() const;
    int			getGradeExec() const;
    int			getGradeSign() const;
    bool		getSign() const;

    void	beSigned(Bureaucrat &bureaucrat);
//	virtual void execute(Bureaucrat const &executor) const = 0;
    virtual void execute(const Bureaucrat &executor) const = 0;

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

};

std::ostream& operator<< (std::ostream &out, const Form &form);

#endif