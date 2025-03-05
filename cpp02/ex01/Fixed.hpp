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
};
std::ostream& operator<<(std::ostream& outputStream, const Fixed& fixed);

# endif