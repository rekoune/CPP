#include "Bureaucrat.hpp"

int main (){
    try{
        Bureaucrat test("bur1", 1);
        std::cout<< test;
        try{
            test.incrementGrade();
            std::cout<< test;
        }catch (std::exception & e){
            std::cout << "Increment " << e.what() << std::endl;
        }
        try{
            test.decrementGrade();
            std::cout << test;
        }catch (std::exception & e){
            std::cout << "Decrement " << e.what() << std::endl;
        }
    }catch (std::exception & e){
        std::cout << "Creation " << e.what() << std::endl;
    }
}