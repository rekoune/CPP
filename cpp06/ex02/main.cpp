# include <cstdlib>
# include <iostream>
# include <ctime>
# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <exception>

typedef std::string String;

Base * generate(void){
    int randValue;

    randValue = rand() % 3;
    switch (randValue){
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
        default: return new A();
    }

}

void identify(Base* p){
    String messages[] = {"The Real Type is an A",
                            "The Real Type is a B",
                            "The Real Type is a C",
                            "Uknown type"};
    int i = 3;

    if ( dynamic_cast<A*>(p) )
        i = 0;
    else if ( dynamic_cast<B*>(p) )
        i = 1;
    else if ( dynamic_cast<C*>(p) )
        i = 2;
    std::cout << messages[i] << std::endl;
}

void identify(Base& p){
    String messages[] = {"The Real Type is an A",
                            "The Real Type is a B",
                            "The Real Type is a C",
                            "Uknown type"};
    int i = 3;
    try{
        dynamic_cast<A&>(p);
        i = 0;
    }catch (std::exception& e){
        try{
            dynamic_cast<B&>(p);
            i = 1;
        }catch (std::exception& e){
            try{
                dynamic_cast<C&>(p);
                i = 2;
                }catch (std::exception& e){
                }
            }
    }
    std::cout << messages[i] << std::endl;
}

int main (){
    srand(time(NULL));
    Base*  base = generate();
    Base& baseRef = *base;
    
    identify(base);
    identify(baseRef);
    delete base;
}