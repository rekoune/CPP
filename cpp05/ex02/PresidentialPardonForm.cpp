# include "PresidentialPardonForm.hpp"
# include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), target("DEFAULT"){
    std::cout << "The Default Constructor of PresidentialPardonForm Called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(String _target): AForm("PresidentialPardonForm", 25, 5), target(_target){
    std::cout << "The Overloaded Constructor of PresidentialPardonForm Called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& original)
        : AForm(original.getName(), original.getGradeToSign(), original.getGradeToExecute()), target(original.target){
        setSign(original.getIsSigned());
        std::cout << "The Copy Constructor of PresidentialPardonForm  Called" << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "The Destructor of PresidentialPardonForm Called" << std::endl;
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& original){
    setSign(original.getIsSigned());
    return (*this);
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!getIsSigned())
        throw (NotSignedException());
    else if (getGradeToExecute() < executor.getGrade())
        throw (GradeTooLowException());
    std::cout <<  target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
