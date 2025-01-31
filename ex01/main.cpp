#include "Bureaucrat.hpp"
#define SEPARATOR std::cout << "------------------------------------" << std::endl;


int main() {
    try {
    Bureaucrat test_1(160, "test_1");
    }
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << '\n';
    }

    try {
    Bureaucrat test_2(-15, "test_2");
    }
    catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << '\n';
    }
    SEPARATOR
    Bureaucrat test_5(2, "test_5");
    Bureaucrat test_6(149, "test_6");

    std::cout << test_5;
    test_5.gradeIncrease();
    std::cout << test_5;
    try {
        test_5.gradeIncrease();
    }
    catch (Bureaucrat::GradeTooHighException &e){
        std::cout << e.what() << '\n';
    }
    std::cout << test_5 << std::endl;

    SEPARATOR
    std::cout << test_6 << std::endl;
    test_6.gradeDecrease();
    std::cout << test_6;
    try {
    test_6.gradeDecrease();
    }
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << '\n';
    }
    std::cout << test_6 << std::endl;

    return 0;
}