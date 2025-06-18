# ifndef ITER_hpp
# define ITER_hpp

# include <iostream>

template<typename A, typename F>
void iter(A* array, int size, F func){
    for (int i = 0; i < size; i++){
        func(array[i]);
    }
}

template<typename T, typename N>
void printElements(T elements, N size){
    std::cout << "[";
    for (int i = 0; i < size - 1; i++){
        std::cout << elements[i] << ", ";
    }
    std::cout << elements[size - 1] << "]" << std::endl;
}

# endif