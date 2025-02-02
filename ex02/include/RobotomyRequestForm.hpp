#pragma once

#include "AForm.hpp"
#include <iostream>
#include<cstdlib>


class RobotomyRequestForm : public AForm {
private:
    const std::string _target;
public:
    RobotomyRequestForm(const std::string &_target);
    RobotomyRequestForm(const RobotomyRequestForm &copy);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &source);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const & executor) const;
};