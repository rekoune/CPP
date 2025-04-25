# include "AForm.hpp"
# include "Bureaucrat.hpp"

AForm::AForm(): name("NULL"), isSigned(false), gradeToSign(150), gradeToExecute(150){
    std::cout << "The Default Constructor of AForm Called" << std::endl;
}
AForm::AForm(const String _name, const int _gradeToSign, const int _gradeToExecute)
        : name(_name), isSigned(false), gradeToSign(_gradeToSign), gradeToExecute(_gradeToExecute){
        std::cout << "The Overloaded Constructor of AForm Called" << std::endl;
        if (gradeToExecute < 1 || gradeToSign < 1)
            throw GradeTooHighException();
        if (gradeToExecute > 150 || gradeToSign > 150)
            throw GradeTooLowException();
}
AForm::AForm(const AForm& original)
        : name(original.name), isSigned(original.isSigned), gradeToSign(original.gradeToSign), gradeToExecute(original.gradeToExecute){
        std::cout << "The Copy Constructor of AForm  Called" << std::endl;
}
AForm::~AForm(){
    std::cout << "The Destructor of AForm Called" << std::endl;
}
AForm& AForm::operator=(const AForm& original){
    isSigned = original.getIsSigned();
    return (*this);
}


const String    AForm::getName() const{
    return (name);
}
bool            AForm::getIsSigned() const{
    return (isSigned);
}
int       AForm::getGradeToSign() const{
    return (gradeToSign);
}
int       AForm::getGradeToExecute() const{
    return (gradeToExecute);
}
void       AForm::setSign(bool sign){
    this->isSigned = sign;
}

void AForm::beSigned(Bureaucrat & bureaucrat){
    if (bureaucrat.getGrade() > gradeToSign)
        throw (GradeTooLowException());
    isSigned = true;
}


const char * AForm::GradeTooHighException:: what() const throw(){
    return ("Exception : Grade is Too Hight");
}
const char * AForm::GradeTooLowException:: what() const throw(){
    return ("Exception : Grade is Too Low");
}
const char * AForm::NotSignedException:: what() const throw(){
    return ("Exception : Form is Not Signed");
}

std::ostream & operator<<(std::ostream & os, AForm & Aform){
    std::cout << Aform.getName() 
            << ", AForm sign = "<< Aform.getIsSigned() 
            << ", Sign Grade = " << Aform.getGradeToSign()
            << ", Execution Grade = " << Aform.getGradeToExecute()
            << std::endl;
    return (os);
}