# include "Point.hpp"

Point::Point(): x(0), y(0){
}

Point::Point(const float X, const float Y) : x(X), y(Y){
}

Point::Point( const Point& original ){
    *this = original;
}

Point::~Point(){

}

Point& Point::operator=(const Point& original){
    (void) original;
    return (*this);
}

const Fixed Point::getX() const {
    return (this->x);
}
const Fixed Point::getY() const {
    return (this->y);
}
