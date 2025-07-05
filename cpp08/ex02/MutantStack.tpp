# include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(){

}
template <typename T>
MutantStack<T>::~MutantStack(){

}
template <typename T>
 MutantStack<T>::MutantStack( const MutantStack<T>& original){
    *this = original;
 }

template <typename T>
MutantStack<T>& MutantStack<T>::operator=( const MutantStack<T>& original){
    if (this != &original){
        std::stack<T>::operator=(original);
    }
    return (*this); 
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin ( void){
    return (this->c.begin());
}
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end ( void){
    return (this->c.end());
}
