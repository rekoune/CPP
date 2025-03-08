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
    Fixed surfaceABC = triangleSurface(a, b, c);
    Fixed surfaceAPB = triangleSurface(a, point, b);
    Fixed surfaceBPC = triangleSurface(b, point, c);
    Fixed surfaceCPA = triangleSurface(c, point, a);
    Fixed total = surfaceAPB + surfaceBPC + surfaceCPA;

    if (surfaceAPB == 0 || surfaceBPC == 0 || surfaceCPA == 0 || surfaceABC != total)
        return (false);
    return (true);
}