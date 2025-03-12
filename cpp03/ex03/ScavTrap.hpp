# ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
    public:
        ScavTrap();
        ScavTrap(const ScavTrap& original);
        ScavTrap (const std::string& name);
        ~ScavTrap();
        ScavTrap& operator=(const ScavTrap& original);
        void guardGate();
        void attack( const std::string& target );
};


# endif