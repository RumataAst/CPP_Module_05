#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(unsigned int grade, const std::string &name) 
        : _name(name) {
            if (grade > LOWGRADE)
                throw (GradeTooLowException());
            else if (grade < HIGHGRADE)
                 throw (GradeTooHighException());
            else
                this->_grade = grade;
        }

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
    *this = copy;
}

Bureaucrat &Bureaucrat::operator= (const Bureaucrat &source) {
    if (this != &source) {
        this->_grade = source._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

unsigned int    Bureaucrat::getGrade() const {
    return _grade;
}

std::string     Bureaucrat::getName() const {
    return _name;
}

void    Bureaucrat::gradeIncrease() {
    if (getGrade() == HIGHGRADE)
        throw (GradeTooHighException());
    else
        this->_grade--;
}

void    Bureaucrat::gradeDecrease() {
    if (getGrade() == LOWGRADE)
        throw (GradeTooLowException());
    else
        this->_grade++;
}

std::ostream &operator <<(std::ostream &out, const Bureaucrat &Bureaucrat) {
    out << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << "." << std::endl;
    return out;
}


