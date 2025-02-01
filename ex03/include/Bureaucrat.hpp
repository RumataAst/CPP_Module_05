#pragma once

#include <iostream>
#include "Form.hpp"
#define LOWGRADE 150
#define HIGHGRADE 1
class Form;

class Bureaucrat {
protected:
    int        _grade;
    const std::string   _name;

public:
    Bureaucrat(int grade,const std::string &name);
    Bureaucrat(const Bureaucrat &copy);
    Bureaucrat &operator= (const Bureaucrat &source);
    ~Bureaucrat();

    int    getGrade() const;
    const std::string     &getName() const;

    void    gradeIncrease();
    void    gradeDecrease();

    class   GradeTooHighException : public std::exception {
        public:
            const char*		what() const throw() {
                return ("Nobody should rise above 1st rank");
            }
    };
    class   GradeTooLowException : public std::exception {
        public:
            const char*     what() const throw() {
                return ("The grade 150 is the lowest of the low");
            }
    };

    void signForm(Form &form);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &Bureaucrat);