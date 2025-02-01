#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

#define LOWGRADE_FORM 150
#define HIGHGRADE_FORM 1

class Bureaucrat;

class AForm {
private:
    const std::string   _name;
    bool                _signed;
    const int           _gradeToSign;
    const int           _gradeToExec;

public:
    AForm(const std::string &name, const int gradeToSign, const int gradeToExec);
    AForm(const AForm &copy);
    AForm &operator=(const AForm &source);
    virtual ~AForm();

    int beSigned(Bureaucrat &bureaucrat);

    class   GradeTooHighException : public std::exception {
        public:
            const char*		what() const throw() {
                return ("Regular form grade should be accessable to personal up to 1 rank");
            }
    };
    class   GradeTooLowException : public std::exception {
        public:
            const char*     what() const throw() {
                return ("Please, the lowest can be only 150. Serious matters only");
            }
    };

    const std::string   &getName() const;
    bool                getSignedStatus() const;
    int                 getGradeToSign() const;
    int                 getGradeToExec() const;
};

std::ostream &operator<<(std::ostream &out, const AForm &AForm);