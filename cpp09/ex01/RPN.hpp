# ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>
# include <sstream>
# include <cstdlib>

typedef std::string String;

class RPN {
    private:
        RPN();
        std::stack<double> container;
        String  expression;
    public:
        RPN(const RPN& original);
        ~RPN();
        RPN& operator=(const RPN& original);
        RPN(const String& expression);
        double  getResult( void );
        int    isOperator( char& c);
        void    makeOperation(int& oper);
        double  doCalculation(double& a, double& b, int& oper);

};

# endif