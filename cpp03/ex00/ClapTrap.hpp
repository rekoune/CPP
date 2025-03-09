# ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap{
    private:
        std::string     name;
        int    hitPoints;
        int    energyPoints;
        int    attackDamage;
    public:
        ClapTrap();
        ClapTrap(const std::string& name);
        ClapTrap(const ClapTrap& original);
        ~ClapTrap();
        ClapTrap& operator=(const ClapTrap& original);


        void attack( const std::string& target );
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string getName( void ) const;
        int getHitPoint( void ) const;
        int getEnergyPoints( void )const;
        int getattackDamage( void )const;

        void     setName( const std::string& name ) ;
        void     setHitPoint( const int& hitPoints ) ;
        void     setEnergyPoints( const int& energyPoints );
        void     setattackDamage( const int& attackDamage );
};

# endif