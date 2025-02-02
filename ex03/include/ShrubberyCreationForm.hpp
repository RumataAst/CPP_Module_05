#pragma once

#include "AForm.hpp"
#include <iostream>
#include <fstream>  

class   ShrubberyCreationForm: public AForm{
private:
    const std::string _target;
public:
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &copy);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &source);
    ~ShrubberyCreationForm();

    void execute(Bureaucrat const & executor) const;
};