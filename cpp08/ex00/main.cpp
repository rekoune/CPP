# include "easyfind.hpp"
# include <vector>
# include <list>
# include <set>

int main (){
    std::srand(time(NULL));
    std::vector<int> vector;
    std::list<int> list;
    std::set<int> set;
    int toFind = 7;

    randomValues(vector, 10, 15);
    randomValues(list, 13, 15);
    randomValues(set, 10, 100);

    std::cout << "================== List   =========================" << std::endl;
    findValue(list, toFind);
    std::cout << "================== Vector =========================" << std::endl;
    findValue(vector, toFind);
    std::cout << "==================  Set   =========================" << std::endl;
    findValue(set, toFind);
}