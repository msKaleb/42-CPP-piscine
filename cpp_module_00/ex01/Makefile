# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 12:19:28 by msoria-j          #+#    #+#              #
#    Updated: 2023/10/21 19:06:13 by msoria-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	PhoneBook.cpp \
				main.cpp \
				Contact.cpp \
				
CFLAGS	=	-Wall -Wextra -Werror -ggdb -O0 -std=c++98
CC			=	c++
NAME		=	phonebook
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