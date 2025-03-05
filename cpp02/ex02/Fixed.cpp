# include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed(){
    numberValue = 0;
}

Fixed::Fixed(const Fixed& original){
    *this = original;
}

Fixed& Fixed::operator=(const Fixed& original){
    if (this != &original)
       this->numberValue = original.getRawBits();
    return (*this);
}

Fixed::~Fixed(){
}

int Fixed::getRawBits ( void ) const{
    return (this->numberValue);
}

void    Fixed::setRawBits ( int const raw){
    this->numberValue = raw;
}

Fixed::Fixed( const int intNumber){
    numberValue = intNumber << fractionalBits;
}
Fixed::Fixed( const float floatNumber){
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

bool Fixed::operator>( const Fixed& toCompare) const {
    return (this->numberValue > toCompare.numberValue);
}
bool Fixed::operator<( const Fixed& toCompare) const {
    return (this->numberValue < toCompare.numberValue);
}
bool Fixed::operator<=( const Fixed& toCompare) const {
    return (this->numberValue <= toCompare.numberValue);
}
bool Fixed::operator>=( const Fixed& toCompare) const {
    return (this->numberValue >= toCompare.numberValue);
}
bool Fixed::operator==( const Fixed& toCompare) const {
    return (this->numberValue == toCompare.numberValue);
}
bool Fixed::operator!=( const Fixed& toCompare) const {
    return (this->numberValue != toCompare.numberValue);
}


Fixed Fixed::operator+( const Fixed& toAdd) const {
    return (Fixed(this->toFloat() + toAdd.toFloat()));
}
Fixed Fixed::operator-( const Fixed& toSubstruct) const {
    return (Fixed(this->toFloat() - toSubstruct.toFloat()));
}
Fixed Fixed::operator*( const Fixed& toMultiply) const {
    return (Fixed(this->toFloat() * toMultiply.toFloat()));
}
Fixed Fixed::operator/( const Fixed& toDivide)const {
    return (Fixed(this->toFloat() / toDivide.toFloat()));
}

Fixed& Fixed::operator++ (){
    ++this->numberValue;
    return (*this);
}

Fixed& Fixed::operator-- (){
    --this->numberValue;
    return (*this);
}

Fixed Fixed::operator++( int ){
    Fixed temp(*this);
    this->numberValue++;
    return (temp);
}
Fixed Fixed::operator--( int ){
    Fixed temp(*this);
    this->numberValue--;
    return (temp);
}

Fixed& Fixed::min (Fixed& fixed1, Fixed& fixed2){
    if (fixed1 < fixed2)
        return (fixed1);
    return (fixed2);
}
const Fixed& Fixed::min (const Fixed& fixed1, const Fixed& fixed2){
    if (fixed1 < fixed2)
        return (fixed1);
    return (fixed2);
}
Fixed& Fixed::max (Fixed& fixed1, Fixed& fixed2){
    if (fixed1 > fixed2)
        return (fixed1);
    return (fixed2);
}
const Fixed& Fixed::max (const Fixed& fixed1, const Fixed& fixed2){
    if (fixed1 > fixed2)
        return (fixed1);
    return (fixed2);
}
