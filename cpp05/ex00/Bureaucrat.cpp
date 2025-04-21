# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
        :name("NULL"), grade(150){
            std::cout << "The default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const String _name, int _grade) 
        :name(_name), grade(_grade){
            if (grade < 1)
                throw GradeTooHighException();
            else if (grade > 150)
                throw GradeTooLowException();
            std::cout << "The Overloaded Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& original)
        : name(original.getName()), grade(original.getGrade()){
            std::cout << "The Copy Constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "The Destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& original){
    this->grade = original.getGrade();
    return (*this);
}


void Bureaucrat::incrementGrade(){
    if (this->grade == 1)
        throw GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrementGrade(){
    if (this->grade == 150)
        throw GradeTooLowException();
    this->grade++;
}





const String  Bureaucrat::getName() const{
    return (this->name);
}
int     Bureaucrat::getGrade() const{
    return (this->grade);
}

const char * Bureaucrat::GradeTooHighException:: what() const throw(){
    return ("Exception : Grade is Too Hight");
}
const char * Bureaucrat::GradeTooLowException:: what() const throw(){
    return ("Exception : Grade is Too Low");
}

std::ostream & operator<<(std::ostream & os, Bureaucrat & bureaucrat){
    std::cout << bureaucrat.getName() << ", bureaucrat grade "<< bureaucrat.getGrade() << std::endl;
    return (os);
}