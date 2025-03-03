# include "Harl.hpp"


int main (){
    Harl test;
    test.complain("WARNING");
    test.complain("INFO");
    test.complain("DEBUG");
    test.complain("ERROR");
    test.complain("notfound");
    test.complain("ERROR");
}