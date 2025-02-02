#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

#define SEPARATOR std::cout << "------------------------------------" << std::endl;


int main() {
    Intern someRandomIntern;
    AForm   *rrf_1 ,*rrf_2, *rrf_3, *rrf_4;

    rrf_4 = NULL;
    // Intern can create 3 forms: Presidential Pardon Form; Robotomy Request Form; Shrubbery Creation Form
    rrf_1 = someRandomIntern.makeForm("Presidential Pardon Form", "Bender");
    rrf_2 = someRandomIntern.makeForm("Robotomy Request Form", "Bender");
    rrf_3 = someRandomIntern.makeForm("Shrubbery Creation Form", "Bender");
    try {
        rrf_4 = someRandomIntern.makeForm("afjpa", "Bender");
        std::cout << "4tf form " << *rrf_4 << std::endl;
    }
    catch (Intern::BadFormException &e) {
        std::cout << e.what () << std::endl;
    }
    std::cout << "4tf form " << *rrf_4 << std::endl;

    // std::cout << "1st form " << *rrf_1 << std::endl;
    // std::cout << "2nd form " << *rrf_2 << std::endl;
    // std::cout << "3rd form " << *rrf_3 << std::endl;

    // Bureaucrat loser(150, "loser");
    // Bureaucrat boss(1, "boss");

    // SEPARATOR
    // boss.signForm(*rrf_1);
    // rrf_1->execute(loser);
    // rrf_1->execute(boss);

    // SEPARATOR
    // boss.signForm(*rrf_2);
    // rrf_2->execute(loser);
    // rrf_2->execute(boss);

    // SEPARATOR
    // boss.signForm(*rrf_3);
    // rrf_3->execute(loser);
    // rrf_3->execute(boss);

    delete rrf_1;
    delete rrf_2;
    delete rrf_3;

    return 0;
}