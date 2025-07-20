# ifndef DEQUE_HPP
# define DEQUE_HPP

# include <deque>
# include <list>

class Deque{
    private:
        std::deque<int> container;
    public:
        Deque();
        ~Deque();
        Deque (std::list<int>& numbersList);
        Deque(const Deque& original);
        Deque& operator=(const Deque& original);
        void    initialize (std::list<int>& numbersList);
        void    sort();
};

# endif