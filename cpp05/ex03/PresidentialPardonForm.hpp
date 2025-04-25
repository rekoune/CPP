# ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm{
    private:
        const String    target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(String _target);
        PresidentialPardonForm(const PresidentialPardonForm& original);
        ~PresidentialPardonForm();
        PresidentialPardonForm& operator=(const PresidentialPardonForm& original);
        
        void execute(Bureaucrat const & executor) const ;
};

# endif