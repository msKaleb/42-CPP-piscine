#include "DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
	// temporal instances for the getters
	ScavTrap	scavTrapTmp("scavTrapTmp");
	FragTrap	fragTrapTmp("fragTrapTmp");

	std::cout << CYAN << "DiamondTrap constructor called with name [" 
		<< name << "]" << std::endl << RESET;
	
	// use the getters to initialise the attributes
	this->_hitPoints = fragTrapTmp.getHitPoints();
	this->_energyPoints = scavTrapTmp.getEnergyPoints();
	this->_attackDamage = fragTrapTmp.getAttackDamage();
}

DiamondTrap::DiamondTrap( const DiamondTrap & src ) : ClapTrap(src), ScavTrap(src), FragTrap(src) {
	std::cout << CYAN << "DiamondTrap copy constructor called for [" 
	<< this->getName() << "]" << std::endl << RESET;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap() {
	std::cout << BLUE << "DiamondTrap destructor called for ["
		<< this->getName() << "]" << std::endl << RESET;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DiamondTrap &				DiamondTrap::operator=( DiamondTrap const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	ClapTrap::operator=(rhs);
	return *this;
}

std::ostream	&operator<<( std::ostream &o, DiamondTrap const &i )
{
	o << std::endl;
	o << "Printing info from " << i.getName() << std::endl;;
	o << "DiamondTrap name: " << i.getName() << std::endl;
	o << "DiamondTrap clapTrapName: " << i.getClapTrapName() << std::endl;
	o << "DiamondTrap Hit Points: " << i.getHitPoints() << std::endl;
	o << "DiamondTrap Energy Points: " << i.getEnergyPoints() << std::endl;
	o << "DiamondTrap Attack Damage: " << i.getAttackDamage() << std::endl;

	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void	DiamondTrap::attack(std::string const &target) {
	ScavTrap::attack(target);
	if (this->_energyPoints > 0)
		this->_energyPoints--;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string		DiamondTrap::getName(void) const { return (this->_name); }

std::string	DiamondTrap::getClapTrapName(void) const {
	std::string	clapTrapName = ClapTrap::getName();
	return clapTrapName;
}
/* ************************************************************************** */
