# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
}
ScalarConverter::ScalarConverter(ScalarConverter & original){
    (void) original;
}
ScalarConverter::~ScalarConverter(){
}
ScalarConverter& ScalarConverter::operator=(ScalarConverter & original){
    (void) original;
    return (*this);
}


void ScalarConverter::convert ( String literal){
    TypeDetector typeDetector(literal);
    typeDetector.literalType();
    if (typeDetector.getType() != "invalid"){
        typeDetector.literalValidator();
        typeDetector.displayLiterals(
                    static_cast<char>(typeDetector.getHolder()),
                    static_cast<int>(typeDetector.getHolder()),
                    static_cast<float>(typeDetector.getHolder()),
                    static_cast<double>(typeDetector.getHolder())
                    );  
    }
} 