#include "ShrubberyCreationForm.hpp"

#define SHRUBBERY_CREATION_TO_SIGN 145
#define SHRUBBERY_CREATION_TO_EXEC 137

#define WIDTH   5

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) 
        : AForm("Shrubbery Creation Form", SHRUBBERY_CREATION_TO_SIGN, SHRUBBERY_CREATION_TO_EXEC), _target(target) {
            // std::cout << "Shrubbery Creation Form is created" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) 
        : AForm("Shrubbery Creation Form", SHRUBBERY_CREATION_TO_SIGN, SHRUBBERY_CREATION_TO_EXEC), _target(copy._target) {
            // std::cout << "Copy is created for ShrubberyCreationForm " << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &source) {
    if (this != &source)
        std::cout << "Operator = is not supported for original ShrubberyCreationForm" << std::endl;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    // std::cout << "Destructor is called for ShrubberyCreationForm" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (checkExecStatus(executor) == 0) {
        std::string uniqueName = _target + "_shrubbery";
        const char* file_name = uniqueName.c_str();
        std::ofstream outfile (file_name);
        int width = WIDTH;
        for (int i = 0; i < width; ++i)
        {
            for (int a = 0; a < width -i - 1; ++ a){
                outfile << " ";
            }
            for (int b = 0; b < i*2 + 1; b++){
                outfile << "*";
            }
            outfile << "\n";
        }
        outfile.close();
        std::cout << executor.getName() << " executed Shrubbery Creation Form" << std::endl;
    }
}
