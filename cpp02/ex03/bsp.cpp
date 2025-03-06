# include "Point.hpp"

void printInfo( const Point& A, const Point& B, const Point& C ){
    std::cout << A.getX() * (B.getY() - C.getY()) << " + " 
        << B.getX() * (C.getY() - A.getY()) 
        << " + " << C.getX() * (A.getY() - B.getY())  
        << " = " << (A.getX() * (B.getY() - C.getY()) 
                + B.getX() * (C.getY() - A.getY()) 
                + C.getX() * (A.getY() - B.getY())) /2
        << std::endl;
}

Fixed   triangleSurface(const Point& A, const Point& B, const Point& C)
{
    Fixed   surface;

    printInfo(A, B, C);
    surface =     (A.getX() * (B.getY() - C.getY()) 
                + B.getX() * (C.getY() - A.getY()) 
                + C.getX() * (A.getY() - B.getY()));
    return (surface.toFloat() / 2);
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
    Fixed surfaceABC = triangleSurface(a, b, c);
    Fixed surfaceAPB = triangleSurface(a, point, b);
    Fixed surfaceBPC = triangleSurface(b, point, c);
    Fixed surfaceCPA = triangleSurface(c, point, a);
    Fixed total = surfaceAPB + surfaceBPC + surfaceCPA;
    if (total < 0)
        total = total * -1;

    std::cout << "abc = " << surfaceABC << " apb = " << surfaceAPB << " bpc = " << surfaceBPC << " cpa = " << surfaceCPA << std::endl;
    if (   surfaceABC == 0 
        || surfaceAPB == 0 
        || surfaceBPC == 0 
        || surfaceCPA == 0){
        return (false);
        }
        std::cout << "total surface " << total << std::endl;
    if (surfaceABC == total)
        return true;
    return (false);
}