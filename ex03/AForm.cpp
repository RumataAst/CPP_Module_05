#include "AForm.hpp"

AForm::AForm(const std::string &name, const int gradeToSign, const int gradeToExec )
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
        if (gradeToExec > LOWGRADE_FORM || gradeToSign > LOWGRADE_FORM)
            throw (GradeTooLowException());
        else if (gradeToExec < HIGHGRADE_FORM || gradeToSign < HIGHGRADE_FORM)
            throw (GradeTooHighException());
}

AForm::AForm(const AForm &copy)
     : _name(copy._name), _signed(false), _gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec) {
        // std::cout << "Copy of the object was created" << std::endl;
     }

AForm &AForm::operator = (const AForm &source) {
    if (this != &source) {
        std::cout << "Only 1 original form is allowed" << std::endl;
    }
    return *this;
}

AForm::~AForm () {}

int AForm::beSigned(Bureaucrat &bureaucrat) {
    if (_signed == 1)
        return 2;
    else if (bureaucrat.getGrade() > this->_gradeToSign) {
        throw (GradeTooLowException());
        return 1;
    }
    else {
        this->_signed = true;
        return 0;
    }
}

const std::string &AForm::getName() const {
    return _name;
}

bool        AForm::getSignedStatus() const {
    return _signed;
}

int         AForm::getGradeToSign() const {
    return _gradeToSign;
}

int         AForm::getGradeToExec() const {
    return _gradeToExec;
}

bool AForm::checkExecStatus(Bureaucrat const & executor) const{
    if (executor.getGrade() > this->getGradeToExec()){
        std::cout << "Lesser being is trying to execute the order" << std::endl;
        return 1;
    }
    else if (this->getSignedStatus() == false) {
        std::cout << "The form hasn't been signed yet" << std::endl;
        return 1;
    }
    return 0;
}

std::ostream &operator<<(std::ostream &out, const AForm &Form) {
    out << "Form : " << Form.getName() << " is currently ";
    if (Form.getSignedStatus() == false) {
        out << "not signed.";
    }
    else {
        out << "signed.";
    }
    out << " Minumum grade to sign is " << Form.getGradeToSign() << " and grade to execute " << Form.getGradeToExec();
    return out;
}

