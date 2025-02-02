#include "RobotomyRequestForm.hpp"

#define ROBOTOMY_REQUEST_TO_SIGN 72
#define ROBOTOMY_REQUEST_TO_EXEC 45

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) 
            : AForm("Robotomy Request Form", ROBOTOMY_REQUEST_TO_SIGN, ROBOTOMY_REQUEST_TO_EXEC), _target(target) {
            // std::cout << "Robotomy Request Form is created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) 
        : AForm("Robotomy Request Form", ROBOTOMY_REQUEST_TO_SIGN, ROBOTOMY_REQUEST_TO_EXEC), _target(copy._target) {
            // std::cout << "Copy for Robotomy Request Form is created" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &source) {
    if (this != &source)
        std::cout << "Operator = is not supported for Robotomy Request Form" << std::endl;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (checkExecStatus(executor) == 0) {
        srand(time(NULL));
        int random = (rand() % 2) + 1;

        // std::cout << "Random number is " << random << std::endl;

        std::cout << "Bzzzz BzzzzBzzzz BzzzzBzzzzBzzzz BzzzzBzzzzBzzzzBzzzz" << std::endl;
        if (random % 2) 
            std::cout << this->_target << " has been robotomized successfully." << std::endl;
        else
            std::cout << "The robotomy failed.... you can try again in 50 years" << std::endl;
    }
}
