#include "Bureaucrat.hpp"
#include "Form.hpp"

#define SEPARATOR std::cout << "------------------------------------" << std::endl;


int main() {
    Bureaucrat loser(150, "loser");
    Bureaucrat boss(1, "boss");
    Form    form("big law", 15, 1);
    try {
    Form    form_mistake("mistake", 154, 1);
    }
    catch (Form::GradeTooLowException &e) {
        std::cout << e.what() << '\n';
    }
    try {
    Form    form_mistake_1("mistake", 1, -5);
    }
    catch (Form::GradeTooHighException &e) {
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
    catch (Form::GradeTooLowException &e) {
        std::cout << e.what() << '\n';
    }
    SEPARATOR
    boss.signForm(form);
    boss.signForm(form);

    return 0;
}