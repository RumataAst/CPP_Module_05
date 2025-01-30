#include "Bureaucrat.hpp"
#define SEPARATOR std::cout << "------------------------------------" << std::endl;


int main() {
    Bureaucrat test_1(160, "test_1");
    Bureaucrat test_2(-15, "test_2");
    Bureaucrat test_3(0, "test_3");
    Bureaucrat test_4(151, "test_4");
    Bureaucrat test_5(2, "test_5");
    Bureaucrat test_6(149, "test_6");

    test_5.getName();
    test_5.getGrade();
    test_5.gradeIncrease();
    std::cout << test_5 << std::endl;
    test_5.gradeIncrease();
    std::cout << test_5 << std::endl;

    SEPARATOR

    test_6.getName();
    test_6.getGrade();
    test_6.gradeDecrease();
    std::cout << test_6 << std::endl;
    test_6.gradeDecrease();
    std::cout << test_6 << std::endl;

    return 0;
}