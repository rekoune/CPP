# include "Fixed.hpp"
# include "Point.hpp"


int main( void ) {
    Point A(10, 10);
    Point B(16, 4);
    Point C(4, 4);
    Point O(7.1, 7);
    
    
    if (bsp(A, B, C, O))
        std::cout << "true" << std::endl;
    else 
        std::cout << "false" << std::endl;
    return 0;
}