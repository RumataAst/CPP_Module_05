#include "PresidentialPardonForm.hpp"

#define PRESIDENTIAL_PARDON_TO_SIGN 25
#define PRESIDENTIAL_PARDON_TO_EXEC 5

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) 
            : AForm("Presidential Pardon Form", PRESIDENTIAL_PARDON_TO_SIGN, PRESIDENTIAL_PARDON_TO_EXEC), _target(target) {
            // std::cout << "Presidential Pardon Form is created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) 
        : AForm("Presidential Pardon Form", PRESIDENTIAL_PARDON_TO_SIGN, PRESIDENTIAL_PARDON_TO_EXEC), _target(copy._target) {
            // std::cout << "Copy for Presidential Pardon Form is created" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &source) {
    if (this != &source)
        std::cout << "Operator = is not supported for Presidential Pardon Form" << std::endl;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (checkExecStatus(executor) == 0) {
        std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
    else {
        std::cout << "Who do you think you are to talk to Zaphod Beeblebrox. Be gone!" << std::endl;
    }
}
