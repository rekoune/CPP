# include "Array.hpp"

int main (){
    Array<int> array(2);
    array[0] = 2;
    Array<int> array2(array);

   std::cout << array2[0] << std::endl;
}