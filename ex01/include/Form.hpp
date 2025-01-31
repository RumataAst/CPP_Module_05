#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
    const std::string   _name;
    bool                _signed;
    const int           _gradeToSign;
    const int           _gradeToExec;

public:
    Form(const std::string &name, bool sign, const int gradeToSign, const int gradeToExecs);
    Form(const Form &copy);
    Form &operator=(const Form &source);
    ~Form();

    void beSigned(Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &out, const Form &Form);