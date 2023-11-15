#include "DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name) {
	std::cout << CYAN << "DiamondTrap constructor called with name [" 
		<< name << "]" << std::endl << RESET;
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap( const DiamondTrap & src ) : ClapTrap(src), ScavTrap(src), FragTrap(src) {
	std::cout << CYAN << "DiamondTrap copy constructor called for [" 
	<< this->getName() << "]" << std::endl << RESET;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap() {
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

/* std::ostream &			operator<<( std::ostream & o, DiamondTrap const & i )
{
	//o << "Value = " << i.getValue();
	return o;
} */


/*
** --------------------------------- METHODS ----------------------------------
*/
void	DiamondTrap::attack(std::string const &target) {
	ScavTrap::attack(target);
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