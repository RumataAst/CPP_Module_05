#pragma once

#include <iostream>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
private:

public:
    Intern();
    Intern(const Intern &copy);
    Intern &operator=(const Intern &source);
    ~Intern();

    AForm* makeForm(std::string formName, std::string formTarget); 
    class BadFormException : public std::exception {
        public:
            const char*     what() const throw() {
                return ("Bad form, please choose one of the following: Presidential Pardon Form, Robotomy Request Form, Shrubbery Creation Form");
            }
    };
};