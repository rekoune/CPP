# include "easyfind.hpp"

template <typename T>
int easyfind(T container, int toFind){
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), toFind);
    if (it == container.end())
        throw NotFoundException(); 
    return (*it);
}

template < typename T>
void randomValues(T& container, int size, int maxValue){
    for(int i = 0; i < size; i++)
        container.insert(container.end(), rand() % maxValue);
}

template <typename T>
void findValue(T container, int toFind){
    int founded;

    try{
        containerElements(container);
        founded = easyfind(container, toFind);
        std::cout << "The value " << founded << " found on the container" << std::endl;
    }catch(NotFoundException& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
}

template < typename T>
void containerElements(T& container){
     typename T::iterator it = container.begin();
     typename T::iterator itCopy = it;
     std::cout << "Container elements: [";
     for(; it != container.end(); it++){
        std::cout << *it ;
        if (++itCopy != container.end())
            std::cout << ", ";
     }
     std::cout << "]" << std::endl;
}