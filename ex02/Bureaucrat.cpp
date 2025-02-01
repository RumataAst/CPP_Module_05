#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(int grade, const std::string &name) 
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

int    Bureaucrat::getGrade() const {
    return _grade;
}

const std::string     &Bureaucrat::getName() const {
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

/*  
    Bureucrate tries to change the signed status in the form class
    by calling member function of Form class. If the grade is not sufficient 
    or the form is already signed print error.
*/
void Bureaucrat::signForm(AForm &form) {
    int result = form.beSigned(*this);
    if (result == 0) {
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    else if (result == 1)
        std::cout << _name << " couldn’t sign " << form.getName()
        << " because the grade is too low" << std::endl;
    else
        std::cout << _name << " couldn’t sign " << form.getName()
        << " because the form was already signed. Kafka sends his regards" << std::endl;
}


std::ostream &operator <<(std::ostream &out, const Bureaucrat &Bureaucrat) {
    out << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << "." << std::endl;
    return out;
}


