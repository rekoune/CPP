# include "RobotomyRequestForm.hpp"
# include "Bureaucrat.hpp"
# include <cstdlib>
# include <ctime>

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), target("DEFAULT"){
    std::cout << "The Default Constructor of RobotomyRequestForm Called" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(String _target): AForm("RobotomyRequestForm", 72, 45), target(_target){
    std::cout << "The Overloaded Constructor of RobotomyRequestForm Called" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& original)
        : AForm(original.getName(), original.getGradeToSign(), original.getGradeToExecute()), target(original.target){
        setSign(original.getIsSigned());
        std::cout << "The Copy Constructor of RobotomyRequestForm  Called" << std::endl;
}
RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "The Destructor of RobotomyRequestForm Called" << std::endl;
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& original){
    setSign(original.getIsSigned());
    return (*this);
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!getIsSigned())
        throw (NotSignedException());
    else if (getGradeToExecute() < executor.getGrade())
        throw (GradeTooLowException());
    std::cout << "RobotomyRequestForm makes Drilling noise!" << std::endl;
    std::srand(time(0));
    if (std::rand() % 2 == 0)
        std::cout <<  target << ": has been robotomized successfully"<< std::endl;
    else
        std::cout <<  target << ": rebotomizing fails !!"<< std::endl;
}