# ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
    private:
        const String    target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(String _target);
        ShrubberyCreationForm(const ShrubberyCreationForm& original);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& original);
        
        void execute(Bureaucrat const & executor) const ;
};

# endif