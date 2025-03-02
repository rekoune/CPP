#include <iostream>

int main (){
    std::string  string = "HI THIS IS BRAIN";
    std::string* stringPTR = &string;
    std::string& stringREF = string;

    std::cout << "string address           =  " << &string << std::endl;
    std::cout << "string pointer address   =  " << stringPTR << std::endl;
    std::cout << "string reference address =  " << &stringREF << std::endl;

    std::cout << "string           = " << string << std::endl;
    std::cout << "string pointer   = " << *stringPTR << std::endl;
    std::cout << "string reference = " << stringREF << std::endl;
}