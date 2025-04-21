# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

typedef std::string String;

class Bureaucrat{
    private:
        const String    name;
        int             grade;
        class   GradeTooHighException;
        class   GradeTooLowException;
    public:
        Bureaucrat();
        Bureaucrat(const String name, int grade);
        Bureaucrat(const Bureaucrat& original);
        ~Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat& original);

        const String  getName() const;
        int     getGrade() const;
        void    incrementGrade();
        void    decrementGrade();
};

class Bureaucrat::GradeTooHighException : public std::exception{
    public:
        const char* what() const throw();
};

class Bureaucrat::GradeTooLowException : public std::exception{
    public:
        const char* what() const throw();
};

std::ostream & operator<<(std::ostream &os, Bureaucrat & bureaucrat);

# endif  