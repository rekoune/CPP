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
        if (*numbers[0] == '\0' || num < 0 || rest[0] != '\0')
            throw InvalidNumberException();
        numbersList.push_back(num);
        numbers++;
    }
}

void    PmergeMe::sort(){
    vector.initialize(numbersList);
    vector.sort();
}


const char* PmergeMe::InvalidNumberException::what (void) const throw(){
    return ("Error: Invalid numbers!");
}