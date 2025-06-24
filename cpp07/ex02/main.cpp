# include "Array.hpp"

int main (){
    Array<std::string> stringArray(2);
    Array<int> intArray(2);
    Array<int> emptyArray;

    stringArray[0] = "first name";
    stringArray[1] = "last name";
    intArray[0] = 10;
    intArray[1] = 20;

    std::cout << "Empty array befor = " << emptyArray << std::endl;
    emptyArray = intArray;
    std::cout << "Empty array after = " << emptyArray << std::endl;
    std::cout << "String array      = " << stringArray << std::endl;
    std::cout << "Int array         = " << intArray << std::endl;

    {
        Array<std::string> copy(stringArray);
        try{
            std::cout << "String copy       = " << copy << std::endl;
            copy[1] = "test";
        }catch(std::exception& e){
            std::cout << e.what() << std::endl;
        }
    }

}


