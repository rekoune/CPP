# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main (){
    ShrubberyCreationForm form1("target");
    RobotomyRequestForm form2("home");
    PresidentialPardonForm form3("home");
    
    try{
        Bureaucrat bur1("bur1", 1);
        std::cout << "=================================" << std::endl;
        bur1.signForm(form1);
        bur1.signForm(form2);
        bur1.signForm(form3);
        bur1.executeForm(form1);
        bur1.executeForm(form2);
        bur1.executeForm(form3);
        std::cout << "=================================" << std::endl;
    }catch( std::exception & e){
        std::cout << e.what() << std::endl;
    }
    try {
        Bureaucrat bur2("bur2", 30);
        std::cout << "=================================" << std::endl;
        bur2.signForm(form1);
        bur2.signForm(form2);
        bur2.signForm(form3);
        bur2.executeForm(form1);
        bur2.executeForm(form2);
        bur2.executeForm(form3);
        std::cout << "=================================" << std::endl;
    }catch( std::exception & e){
        std::cout << e.what() << std::endl;
    }
}