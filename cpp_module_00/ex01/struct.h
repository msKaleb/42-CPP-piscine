/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:40:48 by msoria-j          #+#    #+#             */
/*   Updated: 2023/10/22 22:42:18 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "colors.h"

typedef struct s_data
{
	std::string	fn;
	std::string	ln;
	std::string	nn;
	std::string	pn;
	std::string	ds;
}				t_data;

#endif /* STRUCT_H */
