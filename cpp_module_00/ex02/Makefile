# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 11:32:33 by msoria-j          #+#    #+#              #
#    Updated: 2023/10/23 12:51:05 by msoria-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	Account.cpp \
				tests.cpp \
				
CPPFLAGS	=	-Wall -Wextra -Werror -ggdb -O0 -std=c++98
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