# ifndef TYPEDETECTOR_HPP
# define TYPEDETECTOR_HPP

# include <iostream>
# include <cctype>

typedef std::string String;

class TypeDetector{
    public:
        TypeDetector( String literal);
        TypeDetector( TypeDetector & original);
        ~TypeDetector();
        TypeDetector& operator=( TypeDetector & original);
        bool        isChar( String literal);
        bool        isInt( String literal);
        bool        isFloat( String literal);
        bool        isDouble( String literal);
        void        literalType ( void );
        String      getType ( void) const;
        String      getLiteral ( void) const;
        double      getHolder ( void) const;
        void        literalValidator ( void );
        String      getCharMsg( void ) const;
        String      getIntMsg( void ) const;
        String      getFloatMsg( void ) const;
        String      getDoubleMsg( void ) const;
        void        displayLiterals( char c, int i, float f, double d ) const;
        bool        checkNan( String literal);
    private:
        TypeDetector();
        String  type;
        String  literal;
        double  holder;
        String  charMsg;
        String  intMsg;
        String  floatMsg;
        String  doubleMsg;
};

# endif