# ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm{
    private:
        const String    target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(String _target);
        RobotomyRequestForm(const RobotomyRequestForm& original);
        ~RobotomyRequestForm();
        RobotomyRequestForm& operator=(const RobotomyRequestForm& original);
        
        void execute(Bureaucrat const & executor) const ;
};

# endif