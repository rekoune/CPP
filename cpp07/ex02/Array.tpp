# include "Array.hpp"

template<typename T>
Array<T>::Array(){
    this->array = NULL;
    this->lenght = 0;
}
template<typename T>
Array<T>::Array(unsigned int n){
    this->array = new T[n];
    this->lenght = n;
}
template<typename T>
Array<T>::Array(const Array& original){
    this->array = NULL;
    *this = original;
}
template<typename T>
Array<T>& Array<T>::operator=(const Array& original){
    if (this == &original)
        return (*this);
    this->lenght = original.size();
    delete[] this->array;
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
const T& Array<T>::operator[](size_t index) const {
    if (index > this->lenght - 1){
        throw IndexOutOfBounds();
    }
    return this->array[index];
}
template<typename T>
const char* Array<T>::IndexOutOfBounds::what( void ) const throw (){
    return "Exception: Index out of bounds";
}

template<typename T>
Array<T>::~Array(){
    delete[] this->array;
}


template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& array){
    size_t i = 0;
    os << "[" ;
    for(; i < array.size(); i++){
        os << array[i];
        if (i < array.size() - 1)
            os << ", ";
    }
    os << "]"; 
    return (os);
}
