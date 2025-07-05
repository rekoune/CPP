# include "MutantStack.hpp"
# include <list>

int main()
{
    std::cout << "=== Testing MutantStack ===" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(10);
    mstack.push(15);
    mstack.push(20);

    std::cout << "MutantStack top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "After pop(), MutantStack top: " << mstack.top() << std::endl;
    std::cout << "MutantStack size: " << mstack.size() << std::endl;

    std::cout << "MutantStack elements:" << std::endl;
    MutantStack<int>::iterator mit = mstack.begin();
    MutantStack<int>::iterator mite = mstack.end();
    while (mit != mite)
    {
        std::cout << *mit << std::endl;
        ++mit;
    }

    std::cout << std::endl << "=== Testing std::list ===" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(15);
    lst.push_back(20);

    std::cout << "List back (last element): " << lst.back() << std::endl;
    lst.pop_back();
    std::cout << "After pop_back(), list back: " << lst.back() << std::endl;
    std::cout << "List size: " << lst.size() << std::endl;

    std::cout << "List elements:" << std::endl;
    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }
}

