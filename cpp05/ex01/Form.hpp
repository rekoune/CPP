# ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

typedef std::string String;
class Bureaucrat;

class Form {
    private:
        const String    name;
        bool            isSigned;
        const int       gradeToSign;
        const int       gradeToExecute;
        class   GradeTooHighException;
        class   GradeTooLowException;

    public:
        Form();
        Form(const String _name, const int _gradeToSign, const int _gradeToExecute);
        Form(const Form& original);
        ~Form();
        Form& operator=(const Form& original);

        const String    getName() const;
        bool            getIsSigned() const;
        int             getGradeToSign() const;
        int             getGradeToExecute() const;
        void            beSigned(Bureaucrat & bureaucrat);
};      



class Form::GradeTooHighException : public std::exception{
    public:
        const char* what() const throw();
};

class Form::GradeTooLowException : public std::exception{
    public:
        const char* what() const throw();
};

std::ostream & operator<<(std::ostream &os, Form & Form);

# endif