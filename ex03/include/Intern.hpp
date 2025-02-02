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
};