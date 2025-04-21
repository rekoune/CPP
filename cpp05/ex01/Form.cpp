# include "Form.hpp"
# include "Bureaucrat.hpp"

Form::Form(): name("NULL"), isSigned(false), gradeToSign(150), gradeToExecute(150){
    std::cout << "The Default Constructor of Form Called" << std::endl;
}
Form::Form(const String _name, const int _gradeToSign, const int _gradeToExecute)
        : name(_name), isSigned(false), gradeToSign(_gradeToSign), gradeToExecute(_gradeToExecute){
        std::cout << "The Overloaded Constructor of Form Called" << std::endl;
        if (gradeToExecute < 1 || gradeToSign < 1)
            throw GradeTooHighException();
        if (gradeToExecute > 150 || gradeToSign > 150)
            throw GradeTooLowException();
}
Form::Form(const Form& original)
        : name(original.name), isSigned(original.isSigned), gradeToSign(original.gradeToSign), gradeToExecute(original.gradeToExecute){
        std::cout << "The Copy Constructor of Form  Called" << std::endl;
}
Form::~Form(){
    std::cout << "The Destructor of Form Called" << std::endl;
}
Form& Form::operator=(const Form& original){
    isSigned = original.getIsSigned();
    return (*this);
}


const String    Form::getName() const{
    return (name);
}
bool            Form::getIsSigned() const{
    return (isSigned);
}
int       Form::getGradeToSign() const{
    return (gradeToSign);
}
int       Form::getGradeToExecute() const{
    return (gradeToExecute);
}

void Form::beSigned(Bureaucrat & bureaucrat){
    if (bureaucrat.getGrade() > gradeToSign)
        throw (GradeTooLowException());
    isSigned = true;
}


const char * Form::GradeTooHighException:: what() const throw(){
    return ("Exception : Grade is Too Hight");
}
const char * Form::GradeTooLowException:: what() const throw(){
    return ("Exception : Grade is Too Low");
}

std::ostream & operator<<(std::ostream & os, Form & form){
    std::cout << form.getName() 
            << ", Form sign = "<< form.getIsSigned() 
            << ", Sign Grade = " << form.getGradeToSign()
            << ", Execution Grade = " << form.getGradeToExecute()
            << std::endl;
    return (os);
}