/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 06:09:17 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/22 19:41:49 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"
# include "Node.hpp"

class	Character : public ICharacter
{
private:
	/* data */
	std::string const	_name;
	AMateria			**_inventory;	// array of materias, each slot is a pointer
	int					_slots;			// number of occupied slots
	Character();

	// linked list related
	static Node	*_head;
	static Node	*_current;
	static int	_discarded;

public:
	Character(std::string name);
	Character(Character const &copy);
	~Character();
	Character &operator=(const Character &rhs);

	virtual std::string const	&getName() const;
	virtual void				equip(AMateria *m);
	virtual void				unequip(int idx);
	virtual void				use(int idx, ICharacter &target);

	int			getSlotsCount(void) const;
	AMateria	*getSlot(int idx) const;
};

#endif /* CHARACTER_HPP */
