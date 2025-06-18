# include "iter.hpp"

 void toUpper(char &c){
    c -= 32;
 }

 void increment(int &number){
    number++;
 }

void    setNull(std::string &str){
    str = "NULL";
}

int main () {
    char charArray[] = "abdellah";
    int intArray[] = {1, 2, 3, 4};
    std::string stringArray[] = {"Ali", "Ahmed", "Rachid"};

    std::cout << "===== Befor iter function =====" << std::endl;
    printElements(charArray, 8);
    printElements(intArray, 4);
    printElements(stringArray, 3);

    iter(charArray, 8, toUpper);
    iter(intArray, 4, increment);
    iter(stringArray, 3, setNull);
    
    std::cout << "===== After iter function =====" << std::endl;
    printElements(charArray, 8);
    printElements(intArray, 4);
    printElements(stringArray, 3);

}