/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:50:39 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/15 19:16:16 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	/* data */
	FragTrap();
public:
	FragTrap(std::string name);
	FragTrap(FragTrap const &copy);
	virtual ~FragTrap();

	FragTrap	&operator=(FragTrap const &rhs);
	void		highFivesGuys(void) const;
};

#endif /* FRAGTRAP_HPP */
