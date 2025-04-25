# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "Intern.hpp"

int main (){
   AForm *form;
   Intern intern;
    try{
        Bureaucrat bur1("bur1", 1);
        std::cout << "=================================" << std::endl;
        form = intern.makeForm("shrubbery creation", "target");
        bur1.signForm(*form);
        bur1.executeForm(*form);
        delete form;
        form = intern.makeForm("robotomy request", "target");
        bur1.signForm(*form);
        bur1.executeForm(*form);
        delete form;
        std::cout << "=================================" << std::endl;
    }catch( std::exception & e){
        std::cout << e.what() << std::endl;
    }
    try {
        Bureaucrat bur2("bur2", 30);
        std::cout << "=================================" << std::endl;
        form = intern.makeForm("presidential pardon", "target");
        bur2.signForm(*form);
        bur2.executeForm(*form);
        delete form;
        form = intern.makeForm("presidential", "target");
        bur2.signForm(*form);
        bur2.executeForm(*form);
        delete form;
        std::cout << "=================================" << std::endl;
    }catch( std::exception & e){
        std::cout << e.what() << std::endl;
    }
}