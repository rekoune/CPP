# include "Fixed.hpp"
# include "Point.hpp"


int main( void ) {
    Point A(6.0f, 6.0f);
    Point B(8.0f, 3.0f);
    Point C(4.0f, 3.0f);
    Point O(6.0f, 4.0f);
    
    std::cout << "in the main func Ax = " << A.getX() << std::endl;
    bool flag =  bsp(A, B, C, O);
    if (flag)
        std::cout << "true" << std::endl;
    else 
        std::cout << "false" << std::endl;
    return 0;
}