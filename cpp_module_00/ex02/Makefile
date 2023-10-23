# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 11:32:33 by msoria-j          #+#    #+#              #
#    Updated: 2023/10/23 15:02:21 by msoria-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	Account.cpp \
				tests.cpp \
				
CPPFLAGS	=	-Wall -Wextra -Werror -pedantic -std=c++98
CC			=	c++
NAME		=	account
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

.SILENT: