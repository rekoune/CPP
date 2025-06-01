# ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include "TypeDetector.hpp"

typedef std::string String;

class ScalarConverter{
    public:
        static void convert ( String leteral);
    private:
        ScalarConverter();
        ScalarConverter( ScalarConverter & original);
        ~ScalarConverter();
        ScalarConverter& operator=( ScalarConverter & original);
};

# endif