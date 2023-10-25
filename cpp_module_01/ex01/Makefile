# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 17:38:51 by msoria-j          #+#    #+#              #
#    Updated: 2023/10/25 17:39:21 by msoria-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	main.cpp \
				Zombie.cpp \
				
CPPFLAGS	=	-Wall -Wextra -Werror -pedantic -std=c++98
CC			=	c++
NAME		=	zombie
OBJ			=	$(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
			echo "	Created " $(NAME)

clean:		
			echo "	removing files..."
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

# .SILENT: