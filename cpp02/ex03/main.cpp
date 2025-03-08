# include "Fixed.hpp"
# include "Point.hpp"


int main( void ) {
    Point A(10, 10);
    Point B(16, 4);
    Point C(4, 4);
    Point P(10, 7);
    
    if (bsp(A, B, C, P))
        std::cout << "the point is inside of the triangle" << std::endl;
    else 
        std::cout << "the point is outside of the triangle" << std::endl;
    return 0;
}