# include "Span.hpp"

Span::Span(){}

Span::Span (const Span& original){
    this->container = original.getContainer();
    this->size = original.getSize();
    this->spaceLeft = original.getSpaceLeft();
}
Span::Span (unsigned int N){
    this->size = spaceLeft = N;
}
Span::~Span(){
}

Span& Span::operator=( const Span& original){
    if (this == &original)
        return (*this);
    this->container = original.getContainer();
    this->size = original.getSize();
    this->spaceLeft = original.getSpaceLeft();
    return (*this);
}
void Span::addNumber( size_t N ){
    if (spaceLeft < 1)
        throw CapacityException();
    this->container.push_back(N);
    spaceLeft--;
}
void Span::spanElements( void ){
    std::vector<int>::iterator it = this->container.begin();
    std::vector<int>::iterator itCopy = it;
    std::cout << "Container elements: [";
    for(; it != container.end(); it++){
       std::cout << *it ;
       if (++itCopy != container.end())
           std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}


size_t Span::shortestSpan ( void ){
    std::vector<int> containerCopy = this-> container;
    std::sort(containerCopy.begin(), containerCopy.end());
    size_t minSpan;

    if (containerCopy.size() <= 1)
        throw NotFoundException();
    minSpan = containerCopy.at(1) - containerCopy.at(0);
    for (size_t i = 1; i < containerCopy.size() - 1; i++){
        if (minSpan > (size_t)(containerCopy.at(i + 1) - containerCopy.at(i)))
            minSpan = containerCopy.at(i + 1) - containerCopy.at(i);
    }
    return (minSpan);
}

size_t Span::longestSpan ( void ){
    std::vector<int> containerCopy = this-> container;
    std::sort(containerCopy.begin(), containerCopy.end());
    if (containerCopy.size() <= 1)
        throw NotFoundException();
    return (containerCopy.back() - containerCopy.front());
}

const char* Span::CapacityException::what () const throw(){
    return ("Exception: No space left on the container!");
}
const char* Span::NotFoundException::what () const throw(){
    return ("Exception: No Span can be found!");
}

size_t Span::getSize() const {
    return (this->size);
}
size_t Span::getSpaceLeft() const {
    return (this->spaceLeft);
}
std::vector<int> Span::getContainer() const {
    return (this->container);
}