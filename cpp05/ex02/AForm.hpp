# ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <fstream>

typedef std::string String;
class Bureaucrat;

class AForm {
    private:
        const String    name;
        bool            isSigned;
        const int       gradeToSign;
        const int       gradeToExecute;
    public:
        AForm();
        AForm(const String _name, const int _gradeToSign, const int _gradeToExecute);
        AForm(const AForm& original);
        ~AForm();
        AForm& operator=(const AForm& original);

        const String    getName() const;
        bool            getIsSigned() const;
        int             getGradeToSign() const;
        int             getGradeToExecute() const;
        void            setSign(bool sign);
        void            beSigned(Bureaucrat & bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;
        class   GradeTooHighException;
        class   GradeTooLowException;
        class   NotSignedException;
};      



class AForm::GradeTooHighException : public std::exception{
    public:
        const char* what() const throw();
};

class AForm::GradeTooLowException : public std::exception{
    public:
        const char* what() const throw();
};

class AForm::NotSignedException : public std::exception{
    public:
        const char* what() const throw();
};

std::ostream & operator<<(std::ostream &os, AForm & AForm);

# endif