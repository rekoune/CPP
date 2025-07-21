# ifndef DEQUE_HPP
# define DEQUE_HPP

# include <deque>
# include <list>
# include <iostream>
# include <sys/time.h>

class Deque{
    private:
        std::deque<int> container;
        double          sortDuration;
    public:
        Deque();
        ~Deque();
        Deque (std::list<int>& numbersList);
        Deque(const Deque& original);
        Deque& operator=(const Deque& original);
        void    initialize (std::list<int>& numbersList);
        void    sort();
        std::deque<int>    fordJohnsonSort(std::deque<int> numbers);
        std::deque<std::pair<int, int> > makeSortedPairs(std::deque<int> numbers, int& odd);
        void    separatePairs(std::deque<std::pair<int, int> >& pairs, std::deque<int>& winners, std::deque<int>& losers);     
        void    insertIntoWinners(std::deque<int>& winners, std::deque<int>& losers, int& odd);
        int     binarySearch(int& value, std::deque<int>& container);
        int     Jacobsthal(int N);
        std::deque<int>    getInsertionOrder(std::deque<int>& losers);
        void    cleanLosers(std::deque<int>& losers, std::deque<int>& indexes);
        double  getSortingTime(timeval start, timeval end);
        double  getSortDuration( void ); 
        void    printResult( void ); 
};

# endif