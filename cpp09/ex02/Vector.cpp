# include "Vector.hpp"

Vector::Vector(){};
Vector::~Vector(){};

Vector::Vector(const Vector& original){
    *this = original;
}

Vector& Vector::operator=(const Vector& original){
    if (this != &original)
        this->container = original.container;
    return (*this);
}

Vector::Vector(std::list<int>& numberList){
    std::list<int>::iterator it;

    it = numberList.begin();
    while(it != numberList.end()){
        container.push_back(*it);
        it++;
    }
}
void Vector::initialize(std::list<int>& numberList){
    std::list<int>::iterator it;

    it = numberList.begin();
    while(it != numberList.end()){
        container.push_back(*it);
        it++;
    }
}

std::vector<std::pair<int, int> > Vector::makeSortedPairs(std::vector<int> numbers, int& odd){
    std::vector<int>::iterator start = numbers.begin();
    std::vector<int>::iterator end = numbers.end();
    std::vector<std::pair<int, int> > VPairs;
    std::vector<std::pair<int, int> >::iterator it;
    int         temp;

    if (numbers.size() % 2 != 0)
        odd = *(--end);
    while(start != end){
        VPairs.push_back(std::pair<int, int>(*start, *(++start)));
        ++start;
    }
    it = VPairs.begin();
    while (it != VPairs.end()){
        if (it->first < it->second){
            temp = it->second;
            it->second = it->first;
            it->first = temp;
        }
        it++;
    }
    return (VPairs);
}

void    Vector::separatePairs(std::vector<std::pair<int, int> >& pairs, std::vector<int>& winners, std::vector<int>& losers){
    std::vector<std::pair<int, int> >::iterator it;

    it = pairs.begin();
    while(it != pairs.end()){
        winners.push_back(it->first);
        losers.push_back(it->second);
        it++;
    }
}
int Vector::binarySearch(int& value, std::vector<int>& container){
    int left, right, midd;


    left = 0;
    right = container.size();
    while(left < right){
        midd = (right + left) / 2;
        if (value < container[midd])
            right = midd;
        else 
            left = (midd + 1);
    }
    return (left);
}

int Vector::Jacobsthal(int N){
    if (N == 0)
        return (0);
    else if (N == 1)
        return (1);
    return (Jacobsthal(N -1) + (2 * Jacobsthal(N - 2)));
}
std::vector<int>    Vector::getInsertionOrder(std::vector<int>& losers){
    std::vector<int> indexes;
    size_t indx;
    int i = 2;
    
    indx = Jacobsthal(i) - 1;
    while((indx = Jacobsthal(i) - 1) <= (losers.size() - 1)){
        indexes.push_back(indx);
        i++;
    }
    return (indexes);
}
void    Vector::cleanLosers(std::vector<int>& losers, std::vector<int>& indexes){

    for (int i = (int)(indexes.size() - 1); i >= 0; i--)
        losers.erase(losers.begin() + (indexes[i]));
}

 void    Vector::insertIntoWinners(std::vector<int>& winners, std::vector<int>& losers, int& odd){
    int             index;
    std::vector<int> insertOrder;

    insertOrder = getInsertionOrder(losers);
    for (size_t i = 0; i < insertOrder.size(); i++){
        index = binarySearch(losers[insertOrder[i]], winners);
        winners.insert(winners.begin() + index, losers[insertOrder[i]]);
    }
    cleanLosers(losers, insertOrder);
    for (size_t i = 0; i < losers.size(); i++){
        index = binarySearch(losers[i], winners);
        winners.insert(winners.begin() + index, losers[i]);
    }
    if (odd != -1){
        index = binarySearch(odd, winners);
        winners.insert(winners.begin() + index, odd);
    }
 }

std::vector<int>    Vector::fordJohnsonSort(std::vector<int> numbers){
    std::vector<int> winners, losers;
    std::vector<std::pair<int, int> > pairsVector;
    int odd = -1;

    if (numbers.size() == 1)
        return (numbers);
    pairsVector = makeSortedPairs(numbers, odd);
    separatePairs(pairsVector, winners, losers);
    winners = fordJohnsonSort(winners);
    insertIntoWinners(winners, losers, odd);
    return (winners);
}

void Vector::sort(){
    timeval start, end;

    gettimeofday(&start, NULL);
    container = fordJohnsonSort(container);
    gettimeofday(&end, NULL);
    this->sortDuration = getSortingTime(start, end);
}

double  Vector::getSortingTime(timeval start, timeval end){
    long seconds, uSeconds;

    seconds = end.tv_sec - start.tv_sec;
    uSeconds = end.tv_usec - start.tv_usec;
    return ((seconds * 1000000) + uSeconds);
}
double  Vector::getSortDuration( void){
    return (this->sortDuration);
}

void    Vector::printResult( void ){
    std::vector<int>::iterator it;

    it = container.begin();
    while(it != container.end()){
        std::cout << *it;
        if ((it + 1) != container.end())
            std::cout << " ";
        it++;
    }
    std::cout << std::endl;
}
