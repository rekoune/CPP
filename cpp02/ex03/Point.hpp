# ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point{
    private:
        const Fixed x;
        const Fixed y;
    public:
        Point();
        Point(const float X, const float Y);
        Point(const Point& original);
        Point& operator=(const Point& original);
        ~Point();
        const Fixed getX() const;
        const Fixed getY() const;
};
bool bsp( Point const a, Point const b, Point const c, Point const point);

# endif