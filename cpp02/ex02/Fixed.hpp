# ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
# include <iomanip>

class Fixed {
    private:
        int                 numberValue;
        static const int    fractionalBits;
    public:
       Fixed();
       Fixed( const Fixed& original );

       Fixed( const int intNumber);
       Fixed( const float floatNumber);
       float    toFloat( void ) const;
       int      toInt( void ) const;
       Fixed& operator=(const Fixed& original);
       ~Fixed();
       int  getRawBits ( void ) const;
       void setRawBits ( int const raw );

       bool operator>(const Fixed& toCompare) const;
       bool operator<(const Fixed& toCompare) const;
       bool operator<=(const Fixed& toCompare) const;
       bool operator>=(const Fixed& toCompare) const;
       bool operator==(const Fixed& toCompare) const;
       bool operator!=(const Fixed& toCompare) const;

       Fixed    operator+(const Fixed& toAdd) const;
       Fixed    operator-(const Fixed& toSubstruct) const;
       Fixed    operator*(const Fixed& toMultiply) const;
       Fixed    operator/(const Fixed& toDivide) const;

       Fixed&   operator++( void );
       Fixed&   operator--( void );
       Fixed    operator++( int );
       Fixed    operator--( int );

       static Fixed& min (Fixed& fixed1, Fixed& fixed2);
       static const Fixed& min (const Fixed& fixed1, const Fixed& fixed2);
       static Fixed& max (Fixed& fixed1, Fixed& fixed2);
       static const Fixed& max (const Fixed& fixed1, const Fixed& fixed2);
};
std::ostream& operator<<(std::ostream& outputStream, const Fixed& fixed);

# endif