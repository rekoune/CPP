# include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed(){
    std::cout << "Default constructor called" << std::endl;
    numberValue = 0;
}

Fixed::Fixed(const Fixed& original){
    std::cout << "Copy constructor called" << std::endl;
    *this = original;
}

Fixed& Fixed::operator=(const Fixed& original){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &original)
       this->numberValue = original.getRawBits();
    return (*this);
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits ( void ) const{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->numberValue);
}

void    Fixed::setRawBits ( int const raw){
    std::cout << "setRawBits member function called" << std::endl;
    this->numberValue = raw;
}

Fixed::Fixed( const int intNumber){
    std::cout << "Int constructor called" << std::endl;
    numberValue = intNumber << fractionalBits;
}
Fixed::Fixed( const float floatNumber){
    std::cout << "Float constructor called" << std::endl;
    numberValue = roundf(floatNumber * (1 << fractionalBits));
}

int Fixed::toInt( void ) const{
    return (numberValue >> fractionalBits);
}

float Fixed::toFloat( void ) const{
    return ((float)numberValue / (1 << fractionalBits));
}

std::ostream& operator<<(std::ostream& outputStream, const Fixed& fixed) {
    outputStream << fixed.toFloat();
    return outputStream;
}