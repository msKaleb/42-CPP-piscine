/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:33:25 by msoria-j          #+#    #+#             */
/*   Updated: 2023/11/01 12:51:00 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# define RESET	"\033[0m"
# define RED	"\033[31m"
# define GREEN	"\033[32m"

# include <iostream>

class Harl
{
private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

public:
	Harl();
	~Harl();

	void	complaint(std::string level);
};

#endif /* HARL_HPP */