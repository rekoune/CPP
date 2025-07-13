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

// template <typename T>
// void print(T& param){
//     std::cout << param;
// }

int main () {
    char charArray[] = "abdellah";
    int intArray[] = {1, 2, 3, 4};
    std::string stringArray[] = {"Ali", "Ahmed", "Rachid"};

    std::cout << "===== Befor iter function =====" << std::endl;
    printElements(charArray, 8);
    printElements(intArray, 4);
    printElements(stringArray, 3);

    int a = 9;
    iter(charArray, 8, a);
    iter(intArray, 4, increment);
    iter(stringArray, 3, setNull);
    
    std::cout << "===== After iter function =====" << std::endl;
    printElements(charArray, 8);
    printElements(intArray, 4);
    printElements(stringArray, 3);

}

// #include <iostream>
// #include <string>

// iter
// template<typename A, typename F>
// void iter(A* array, int size, F func){
//     for (int i = 0; i < size; i++){
//         func(array[i]);
//     }
// }

// // print
// template <typename T>
// void print(const T& param){
//     std::cout << param << std::endl;
// }

// int main () {
//     char charArray[] = "abdellah";
//     int intArray[] = {1, 2, 3, 4};
//     std::string stringArray[] = {"Ali", "Ahmed", "Rachid"};

//     iter(charArray, 8, &print<char>);
//     iter(intArray, 4, &print<int>);
//     iter(stringArray, 3, &print<std::string>);
// }
