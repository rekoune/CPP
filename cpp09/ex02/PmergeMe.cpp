# include "PmergeMe.hpp"

PmergeMe::PmergeMe(){};
PmergeMe::~PmergeMe(){};

PmergeMe::PmergeMe( const PmergeMe& original){
    *this = original;
}

PmergeMe& PmergeMe::operator=( const PmergeMe& original){
    if (this != &original){
        this->numbersList = original.numbersList;
    }
    return (*this);
}
PmergeMe::PmergeMe(char** numbers){
    try{
        parseNumbers(numbers);
    }catch (InvalidNumberException& e){
        throw e;
    }
}

void PmergeMe::parseNumbers( char** numbers){
    long    num;
    char*   rest;

    numbers++;

    while (*numbers){
        num = std::strtol(*numbers, &rest, 10);
        if (*numbers[0] == '\0' || num < 0 || rest[0] != '\0' || num > std::numeric_limits<int>::max())
            throw InvalidNumberException();
        numbersList.push_back(num);
        numbers++;
    }
}

void    PmergeMe::printNumbersList(){
    std::list<int>::iterator it;

    it = numbersList.begin();
    while(it != numbersList.end()){
        std::cout << *it;
        if (++it != numbersList.end())
            std::cout << " ";
    }
    std::cout << std::endl;
}

void    PmergeMe::displayResult( void ){
    std::cout << "Befor: ";
    printNumbersList();
    std::cout << "After: ";
    vector.printResult();
    std::cout << "Time to process a range of " 
                << numbersList.size() 
                << " elements with std::vector : "
                << vector.getSortDuration() << " us" << std::endl;
    std::cout << "Time to process a range of " 
                << numbersList.size() 
                << " elements with std::vector : "
                << deque.getSortDuration() << " us" << std::endl;
}

void    PmergeMe::sort(){
    vector.initialize(numbersList);
    vector.sort();
    deque.initialize(numbersList);
    deque.sort();
}


const char* PmergeMe::InvalidNumberException::what (void) const throw(){
    return ("Error: Invalid numbers!");
}