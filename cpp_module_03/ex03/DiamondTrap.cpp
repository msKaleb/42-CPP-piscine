#include "DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap() {}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
	
	std::cout << CYAN << "DiamondTrap constructor called with name [" 
		<< name << "]" << std::endl << RESET;
	// std::cout << "ScavTrap::_energyPoints: " << ScavTrap().getEnergyPoints() << std::endl;

	// _hitPoints = tmp->FragTrap::_hitPoints;
	_energyPoints = ScavTrap().getEnergyPoints();
	// _attackDamage = ScavTrap().getAttackDamage();

	// use the getters to initialise the attributes
	/* this->_hitPoints = fragTrapTmp.getHitPoints();
	this->_energyPoints = scavTrapTmp.getEnergyPoints();
	this->_attackDamage = fragTrapTmp.getAttackDamage(); */
}

DiamondTrap::DiamondTrap( const DiamondTrap &src ) : ClapTrap(src), ScavTrap(src), FragTrap(src) {
	std::cout << CYAN << "DiamondTrap copy constructor called for [" 
	<< src.getName() << "]" << std::endl << RESET;
	this->operator=(src);
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

DiamondTrap	&DiamondTrap::operator=( DiamondTrap const &rhs )
{
	if ( this != &rhs ) {
		this->_name = rhs.getName();
		ClapTrap::operator=(rhs);
	}
	return *this;
}

std::ostream	&operator<<( std::ostream &o, DiamondTrap const &i )
{
	o << BOLDMAGENTA << std::endl
		<< "Printing info from " << i.getName() << std::endl
		<< "DiamondTrap name: " << i.getName() << std::endl
		<< "DiamondTrap clapTrapName: " << i.getClapTrapName() << std::endl
		<< "DiamondTrap Hit Points: " << i.getHitPoints() << std::endl
		<< "DiamondTrap Energy Points: " << i.getEnergyPoints() << std::endl
		<< "DiamondTrap Attack Damage: " << i.getAttackDamage() << std::endl
		<< RESET;

	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void	DiamondTrap::attack(std::string const &target) {
	ScavTrap::attack(target);
	/* if (this->_energyPoints > 0)
		this->_energyPoints--; */
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	DiamondTrap::getName(void) const { return (this->_name); }

std::string	DiamondTrap::getClapTrapName(void) const {
	std::string	clapTrapName = ClapTrap::getName();
	return clapTrapName;
}

void	DiamondTrap::whoAmI(void) const {
	std::cout << MAGENTA << std::endl << "whoAmI member function:" << std::endl
		<< "DiamondTrap name: " << this->getName() << std::endl
		<< "ClapTrap name: " << this->getClapTrapName() << std::endl << RESET;
	// std::string	clapTrapName = ClapTrap::getName();
	return ;
}

/* ************************************************************************** */
