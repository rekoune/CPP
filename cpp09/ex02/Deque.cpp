# include "Deque.hpp"

Deque::Deque(){};
Deque::~Deque(){};

Deque::Deque(const Deque& original){
    *this = original;
}

Deque& Deque::operator=(const Deque& original){
    if (this != &original)
        this->container = original.container;
    return (*this);
}

Deque::Deque(std::list<int>& numberList){
    std::list<int>::iterator it;

    it = numberList.begin();
    while(it != numberList.end()){
        container.push_back(*it);
        it++;
    }
}
void Deque::initialize(std::list<int>& numberList){
    std::list<int>::iterator it;

    it = numberList.begin();
    while(it != numberList.end()){
        container.push_back(*it);
        it++;
    }
}

void Deque::sort(){
    
}