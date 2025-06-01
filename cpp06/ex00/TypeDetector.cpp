# include "TypeDetector.hpp"
#include <iomanip>

TypeDetector::TypeDetector(){
}
TypeDetector::TypeDetector( String literal ){
    this->literal = literal;
}
TypeDetector::TypeDetector(TypeDetector & original){
   this->type = original.getType();
   this->literal = original.getLiteral();
   this->type = original.getHolder();
}
TypeDetector::~TypeDetector(){
}
TypeDetector& TypeDetector::operator=(TypeDetector & original){
    this->type = original.getType();
    this->literal = original.getLiteral();
    this->type = original.getHolder();
    return (*this);
}



String    TypeDetector::getType ( void ) const {
    return (this->type);
}
String    TypeDetector::getLiteral ( void ) const {
    return (this->literal);
}
double    TypeDetector::getHolder ( void ) const {
    return (this->holder);
}




bool    TypeDetector::isChar( String literal){
    if (literal.length() != 1 || std::isdigit(literal[0]))
        return (false);
    this->holder = literal[0];
    return (true);
}
bool    TypeDetector::isInt( String literal){
    long number;
    char *rest;

    number = strtol(literal.c_str(), &rest, 10);
    if ((number == 0 && rest[0] != '\0') || rest[0] != '\0')
        return (false);
    this->holder = number;
    return (true);
}
bool    TypeDetector::isFloat( String literal){
    double number;
    char    *rest;

    number = strtod(literal.c_str(), &rest);
    if ((number == 0 && rest[0] != 'f') || rest[0] != 'f' || rest[1] != '\0')
        return (false);
    this->holder = number;
    return (true);
}
bool    TypeDetector::isDouble( String literal){
    double number;
    char    *rest;

    number = strtod(literal.c_str(), &rest);
    if ((number == 0 && rest[0] != '\0') || rest[0] != '\0')
        return (false);
    this->holder = number;
    return (true);
}

void  TypeDetector::literalType ( void ){
    if (isChar(literal))
        this->type =  "char";
    else if (isInt(literal))
        this->type =  "int";
    else if (isFloat(literal))
        this->type =  "float";
    else if (isDouble(literal))
        this->type =  "double";
    else{
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
        this->type = "invalid";
    }
}

bool    TypeDetector::checkNan( String literal ){
    if (literal == "nan" || literal == "-nan" || literal == "+nan"|| literal == "nanf" || literal == "-nanf" || literal == "+nanf")
        return (true);
    return (false);
}

void    TypeDetector::literalValidator ( void ){
    if (this->holder > std::numeric_limits<char>::max() || this->holder < std::numeric_limits<char>::min() || checkNan(this->literal))
        this->charMsg = "impossible";
    else if (!isprint(this->holder))
        this->charMsg = "Non displayable";
    if (this->holder > std::numeric_limits<int>::max() || this->holder < std::numeric_limits<int>::min() || checkNan(this->literal))
        this->intMsg = "impossible";

    if(this->holder > std::numeric_limits<float>::max())
        this->floatMsg = "+inff";
    else if(this->holder < -std::numeric_limits<float>::max())
        this->floatMsg = "-inff";
    else if(this->literal == "+nan" || this->literal == "+nanf")
        this->floatMsg = "+nanf";
    else if(this->literal == "-nan" || this->literal == "-nanf")
        this->floatMsg = "-nanf";

    if(this->holder > std::numeric_limits<double>::max())
        this->doubleMsg = "+inf";
    else if(this->holder < -std::numeric_limits<double>::max())
        this->doubleMsg = "-inf";
    else if(this->literal == "nan" || this->literal == "nanf")
        this->doubleMsg = "nan";
    else if(this->literal == "+nan" || this->literal == "+nanf")
        this->doubleMsg = "+nan";
    else if(this->literal == "-nan" || this->literal == "-nanf")
        this->doubleMsg = "-nan";
}

void        TypeDetector::displayLiterals(char c, int i, float f, double d) const{
    if (!getCharMsg().empty())
        std::cout << "char: " << getCharMsg() << std::endl;
    else
        std::cout << "char: " << "'" << c << "'"<< std::endl;
    if (!getIntMsg().empty())
        std::cout << "int: " << getIntMsg() << std::endl;
    else
        std::cout << "int: " << i << std::endl;
    if (!getFloatMsg().empty())
        std::cout << "float: " << getFloatMsg() << std::endl;
    else
        std::cout  << std::fixed << std::setprecision(1) << "float: " << f << 'f' << std::endl;
    if (!getDoubleMsg().empty())
        std::cout << "double: " << getDoubleMsg() << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

String TypeDetector::getCharMsg( void ) const {
    return (this->charMsg);
}
String TypeDetector::getIntMsg( void ) const {
    return (this->intMsg);
}
String TypeDetector::getFloatMsg( void ) const {
    return (this->floatMsg);
}
String TypeDetector::getDoubleMsg( void ) const {
    return (this->doubleMsg);
}