# include "easyfind.hpp"
# include <array>
# include <vector>
# include <list>
# include <set>

int main (){
    std::srand(time(NULL));
    std::array<int, 4> array;
    std::vector<int> vector;
    std::list<int> list;
    std::set<int> set;
    int toFind = 7;

    array[0] = 4;
    array[1] = 43;
    array[2] = 87;
    array[3] = 7;
    randomValues(vector, 10, 15);
    randomValues(list, 13, 15);
    randomValues(set, 10, 100);

    std::cout << "================== Array  =========================" << std::endl;
    findValue(array, toFind);
    std::cout << "================== List   =========================" << std::endl;
    findValue(list, toFind);
    std::cout << "================== Vector =========================" << std::endl;
    findValue(vector, toFind);
    std::cout << "==================  Set   =========================" << std::endl;
    findValue(set, toFind);
}