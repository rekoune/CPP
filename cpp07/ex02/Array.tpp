# include "Array.hpp"

template<typename T>
Array<T>::Array(){
    std::cout << "hona default ...." << std::endl;
    this->array = NULL;
    this->lenght = 0;
}
template<typename T>
Array<T>::Array(unsigned int n){
    this->array = new T[n];
    this->lenght = n;
}
template<typename T>
Array<T>::Array(Array& original){
    *this = original;
}
template<typename T>
Array<T>& Array<T>::operator=(Array& original){
    this->lenght = original.size();
    std::cout << "hona .. hona" << std::endl;
    delete this->array;
    this->array = new T[lenght];
    for(size_t i = 0; i < lenght; i++){
        this->array[i] = original.array[i];
    }
    return (*this);
}
template<typename T>
size_t Array<T>::size( void ) const{
    return (this->lenght);
}
template<typename T>
T& Array<T>::operator[](size_t index){
    if (index > this->lenght - 1){
        throw IndexOutOfBounds();
    }
    return this->array[index];
}
template<typename T>
const char* Array<T>::IndexOutOfBounds::what( void ) const throw (){
    return "Index out of bounds";
}

template<typename T>
Array<T>::~Array(){
    delete this->array;
}