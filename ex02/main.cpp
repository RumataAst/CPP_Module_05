#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

#define SEPARATOR std::cout << "------------------------------------" << std::endl;


int main() {
    Bureaucrat loser(150, "loser");
    Bureaucrat boss(1, "boss");
    ShrubberyCreationForm Form_1_test("home");
    PresidentialPardonForm Pardon_1_test("Me");
    RobotomyRequestForm Robotomy_1_test("Me");

    // SEPARATOR
    // boss.signForm(Form_1_test);
    // Form_1_test.execute(loser);
    // Form_1_test.execute(boss);

    // SEPARATOR
    // boss.signForm(Pardon_1_test);
    // Pardon_1_test.execute(loser);
    // Pardon_1_test.execute(boss);

    SEPARATOR
    boss.signForm(Robotomy_1_test);
    Robotomy_1_test.execute(loser);
    Robotomy_1_test.execute(boss);

    return 0;
}