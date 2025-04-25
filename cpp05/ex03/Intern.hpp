# ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include <exception>

typedef std::string String;
class Intern {
    public:
        Intern();
        Intern(const Intern& original);
        ~Intern();
        Intern& operator=(const Intern& original);
        AForm*  makeForm(String formName, String formTarget);
        AForm*  shrubberyForm(String formTarget);
        AForm*  robotmyForm(String formTarget);
        AForm*  presidentialForm(String formTarget);
        void    toLowerCase(String & str);
        class   FormNotFoundException : public std::exception{
            public:
                const char* what() const throw();
        };
};

# endif