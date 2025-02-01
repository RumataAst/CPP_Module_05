#include "Bureaucrat.hpp"
#include "AForm.hpp"

#define SEPARATOR std::cout << "------------------------------------" << std::endl;


int main() {
    Bureaucrat loser(150, "loser");
    Bureaucrat boss(1, "boss");
    AForm    form("big law", 15, 1);
    try {
        AForm    form_mistake("mistake", 154, 1);
    }
    catch (AForm::GradeTooLowException &e) {
        std::cout << e.what() << '\n';
    }
    try {
        AForm    form_mistake_1("mistake", 1, -5);
    }
    catch (AForm::GradeTooHighException &e) {
        std::cout << e.what() << '\n';
    }
    SEPARATOR
    std::cout << loser << std::endl;
    std::cout << boss << std::endl;
    std::cout << form << std::endl;

    SEPARATOR
    try {
        loser.signForm(form);
    }
    catch (AForm::GradeTooLowException &e) {
        std::cout << e.what() << '\n';
    }
    SEPARATOR
    boss.signForm(form);
    boss.signForm(form);

    return 0;
}