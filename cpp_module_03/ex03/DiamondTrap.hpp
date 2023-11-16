#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;

		DiamondTrap();

	public:

		DiamondTrap(std::string name);
		DiamondTrap( DiamondTrap const &src );
		virtual ~DiamondTrap();

		DiamondTrap	&operator=( DiamondTrap const &rhs );

		std::string	getName(void) const;
		std::string	getClapTrapName(void) const;
		void		attack(const std::string &target);

};

// std::ostream &			operator<<( std::ostream &o, DiamondTrap const &i );

#endif /* ***************************************************** DIAMONDTRAP_H */
