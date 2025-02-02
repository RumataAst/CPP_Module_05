#include "Intern.hpp"

Intern::Intern() {
    // std::cout << "Intern is created" << std::endl;s
}

Intern::Intern(const Intern &copy) {
    *this = copy;
    // std::cout << "Intern's copy is created" << std::endl;
}

Intern &Intern::operator=(const Intern &source) {
    if (this != &source){
        // std::cout << "Intern's operator = is called" << std::endl;s
    }
    return *this;
}

Intern::~Intern() {
    // std::cout << "Destructor for Intern is called" << std::endl;
}

AForm* Intern::makeForm(std::string formName, std::string formTarget) {
    std::string form_options[3] = {"Presidential Pardon Form", "Robotomy Request Form", "Shrubbery Creation Form"};
    int a = 3;
    for (int i = 0; i < 3; ++i){
        if (form_options[i] == formName) {
            a = i;
            break;
        }
    }
    switch (a) {
        case 0:
            return new PresidentialPardonForm(formTarget);
        case 1:
            return new RobotomyRequestForm(formTarget);
        case 2:
            return new ShrubberyCreationForm(formTarget);
        case 3:
            throw(BadFormException());
    }
    return NULL;
}
