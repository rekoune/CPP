# include "Intern.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <cctype>

Intern::Intern(){
    std::cout << "The Default Constructor of Intern Called" << std::endl;
}
Intern::Intern(const Intern& original){
        std::cout << "The Copy Constructor of Intern  Called" << std::endl;
        (void)original;
}
Intern::~Intern(){
    std::cout << "The Destructor of Intern Called" << std::endl;
}
Intern& Intern::operator=(const Intern& original){
    (void)original;
    return (*this);
}

AForm* Intern::shrubberyForm(String formTarget){
    return new ShrubberyCreationForm(formTarget);
}
AForm* Intern::robotmyForm(String formTarget){
    return new RobotomyRequestForm(formTarget);
}
AForm* Intern::presidentialForm(String formTarget){
    return new PresidentialPardonForm(formTarget);
}

void Intern::toLowerCase(String & str){
    for (size_t i = 0; i < str.length(); i++)
        str[i] = tolower(str[i]);
}

const char* Intern::FormNotFoundException::what () const throw(){
    return ("Exception: Form not found");
}

AForm* Intern::makeForm(String formName, String formTarget){
    AForm* (Intern::*formPTR[3]) (String);
    String  str[3] =  
        {"shrubbery creation", 
        "robotomy request", 
        "presidential pardon"};

    formPTR[0] = &Intern::shrubberyForm;
    formPTR[1] = &Intern::robotmyForm;
    formPTR[2] = &Intern::presidentialForm;
    toLowerCase(formName);

    for ( int i = 0; i < 3; i++)
        if (!formName.compare(str[i])){
            std::cout << "Intern creates " << formName << " form" << std::endl;
            return ((this->*formPTR[i])(formTarget));
        }
    throw   FormNotFoundException();
    return NULL;
}

