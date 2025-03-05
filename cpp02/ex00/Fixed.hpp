# ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
    private:
        int                 numberValue;
        static const int    fractionalBits;
    public:
       Fixed();
       Fixed( const Fixed& original );
       Fixed& operator=(const Fixed& original);
       ~Fixed();
       int  getRawBits ( void ) const;
       void setRawBits ( int const raw );
};

# endif