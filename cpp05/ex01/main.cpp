# include "Bureaucrat.hpp"
# include "Form.hpp"

int main (){
    try{
        Form form1 ("form1", 20, 14);
        Bureaucrat bur1("bur1", 10);
        Form form2 ("form2", 5, 14);
        Bureaucrat bur2("bur2", 6);
        Form form3 ("form3", 100, 14);
        Bureaucrat bur3("bur3", 100);
        bur1.signForm(form1);
        bur2.signForm(form2);
        bur3.signForm(form3);
    }catch (std::exception & e){
        std::cout << e.what() << std::endl;
    }
}