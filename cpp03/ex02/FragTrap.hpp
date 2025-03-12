# ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
    public:
        FragTrap();
        FragTrap(const FragTrap& original);
        FragTrap (const std::string& name);
        ~FragTrap();
        FragTrap& operator=(const FragTrap& original);
        void attack( const std::string& target );
        void highFivesGuys(void);
};


# endif