#pragma once

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm: public AForm {
private:
   const std::string _target;

public:
    PresidentialPardonForm(const std::string &_target);
    PresidentialPardonForm(const PresidentialPardonForm &copy);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &source);
    ~PresidentialPardonForm();

    void execute(Bureaucrat const & executor) const;
};