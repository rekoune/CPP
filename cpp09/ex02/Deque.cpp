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

std::deque<std::pair<int, int> > Deque::makeSortedPairs(std::deque<int> numbers, int& odd){
    std::deque<int>::iterator start = numbers.begin();
    std::deque<int>::iterator end = numbers.end();
    std::deque<std::pair<int, int> > VPairs;
    std::deque<std::pair<int, int> >::iterator it;
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

void    Deque::separatePairs(std::deque<std::pair<int, int> >& pairs, std::deque<int>& winners, std::deque<int>& losers){
    std::deque<std::pair<int, int> >::iterator it;

    it = pairs.begin();
    while(it != pairs.end()){
        winners.push_back(it->first);
        losers.push_back(it->second);
        it++;
    }
}
int Deque::binarySearch(int& value, std::deque<int>& container){
    int left, right, midd;

    static int comp = 0;

    left = 0;
    right = container.size();
    while(left < right){
        comp++;
        midd = (right + left) / 2;
        if (value < container[midd])
            right = midd;
        else 
            left = (midd + 1);
    }
    return (left);
}

int Deque::Jacobsthal(int N){
    if (N == 0)
        return (0);
    else if (N == 1)
        return (1);
    return (Jacobsthal(N -1) + (2 * Jacobsthal(N - 2)));
}
std::deque<int>    Deque::getInsertionOrder(std::deque<int>& losers){
    std::deque<int> indexes;
    size_t indx;
    int i = 2;
    
    indx = Jacobsthal(i) - 1;
    while((indx = Jacobsthal(i) - 1) <= (losers.size() - 1)){
        indexes.push_back(indx);
        i++;
    }
    return (indexes);
}
void    Deque::cleanLosers(std::deque<int>& losers, std::deque<int>& indexes){

    for (int i = (int)(indexes.size() - 1); i >= 0; i--)
        losers.erase(losers.begin() + (indexes[i]));
}

 void    Deque::insertIntoWinners(std::deque<int>& winners, std::deque<int>& losers, int& odd){
    int             index;
    std::deque<int> insertOrder;

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

std::deque<int>    Deque::fordJohnsonSort(std::deque<int> numbers){
    std::deque<int> winners, losers;
    std::deque<std::pair<int, int> > pairsdeque;
    int odd = -1;

    if (numbers.size() == 1)
        return (numbers);
    pairsdeque = makeSortedPairs(numbers, odd);
    separatePairs(pairsdeque, winners, losers);
    winners = fordJohnsonSort(winners);
    insertIntoWinners(winners, losers, odd);
    return (winners);
}

void Deque::sort(){
    timeval start, end;

    gettimeofday(&start, NULL);
    container = fordJohnsonSort(container);
    gettimeofday(&end, NULL);
    this->sortDuration = getSortingTime(start, end);
}

double  Deque::getSortingTime(timeval start, timeval end){
    long seconds, uSeconds;

    seconds = end.tv_sec - start.tv_sec;
    uSeconds = end.tv_usec - start.tv_usec;
    return ((seconds * 1000000) + uSeconds);
}
double  Deque::getSortDuration( void){
    return (this->sortDuration);
}

void    Deque::printResult( void ){
    std::deque<int>::iterator it;

    it = container.begin();
    while(it != container.end()){
        std::cout << *it;
        if ((it + 1) != container.end())
            std::cout << " ";
        it++;
    }
    std::cout << std::endl;
}
