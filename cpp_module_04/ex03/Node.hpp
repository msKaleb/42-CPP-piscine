#ifndef NODE_HPP
# define NODE_HPP

# include <iostream>
# include "AMateria.hpp"

class	Node
{
private:
	/* data */

public:
	/* Orthodox canonical */
	Node();
	~Node();
	Node(Node const &copy);
	Node &operator=(const Node &rhs);

	Node(AMateria *toDiscard);

	// AMateria	*getMateria(void) const;
	AMateria	*discarded;
	Node		*next;

};

#endif /* NODE_HPP */
