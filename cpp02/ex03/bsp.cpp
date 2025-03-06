# include "Point.hpp"

Fixed   triangleSurface(const Point& A, const Point& B, const Point& C)
{
    Fixed   surface;

    surface =     A.getX() * (B.getY() - C.getY()) 
                + B.getX() * (C.getY() - A.getY()) 
                + C.getX() * (A.getY() - B.getY());
    if (surface.getRawBits() < 0)
        surface.setRawBits(surface.getRawBits() * -1);
    return (surface / 2);
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
    std::cout << "in the bsp func Ax = " << a.getX() << std::endl;
    Fixed surfaceABC = triangleSurface(a, b, c);
    Fixed surfaceAPB = triangleSurface(a, point, b);
    Fixed surfaceBPC = triangleSurface(b, point, c);
    Fixed surfaceCPA = triangleSurface(c, point, a);
    if (   surfaceAPB == 0 
        || surfaceAPB == 0 
        || surfaceAPB == 0 
        || surfaceAPB == 0){
        return (false);
        }
    if (surfaceABC == surfaceAPB + surfaceBPC + surfaceCPA)
        return true;
    return (false);
}