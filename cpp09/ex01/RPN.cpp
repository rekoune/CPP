# include "RPN.hpp"

RPN::RPN(){};
RPN::RPN(const RPN& original){
    *this = original;
}
RPN::RPN(const String& expression){
    this->expression = expression;
}
RPN& RPN::operator=(const RPN& original){
    this->expression = original.expression;
    this->container = original.container;
    return (*this);
}

int RPN::isOperator(char& c){
    switch (c){
        case '+':
            return (1);
        case '-':
            return (2);
        case '*':
            return (3);
        case '/':
            return (4);
        default :
            return (0);
    }
}

double  RPN::doCalculation( double& a, double& b, int& oper){
    if (b == 0 && oper == 4){
        std::cerr << "Error: invalid expression" << std::endl;
        exit(1);
    }
    switch (oper){
        case 1:
            return (a + b);
        case 2:
            return (a - b);
        case 3:
            return (a * b);
        case 4:
            return (a / b);
    }
    return (0);
}

void RPN::makeOperation( int& oper ){
    double a, b;
    
    if (container.size() < 2){
        std::cerr << "Error: invalid expression" << std::endl;
        exit(1);
    }
    b = container.top();
    container.pop();
    a = container.top();
    container.pop();
    container.push(doCalculation(a, b, oper));
}

double  RPN::getResult( void ){
    std::stringstream stringStream(expression);
    String token;
    int     oper;

    while(std::getline(stringStream, token, ' ')){
        if (token.size()!= 1){
            std::cerr << "Error: invalid expression" << std::endl;
            exit(1);
        }
        if (std::isdigit(token[0]))
            container.push(std::strtod(token.c_str(), NULL));
        else if ((oper = isOperator(token[0])) > 0)
            makeOperation(oper);
        else{
            std::cerr << "Error: invalid expression" << std::endl;
            exit(1);
        }
    }
    if (container.size()!= 1){
        std::cerr << "Error: invalid expression" << std::endl;
        exit(1);
    }
    return (container.top());
}

RPN::~RPN(){};