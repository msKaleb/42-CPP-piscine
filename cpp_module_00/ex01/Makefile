# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 12:19:28 by msoria-j          #+#    #+#              #
#    Updated: 2023/10/13 15:12:51 by msoria-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	PhoneBook.cpp \
				main.cpp \
#				Contact.cpp \
				
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98
CC			=	c++
NAME		=	phonebook
OBJ			=	$(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
			echo "\tCreated " $(NAME)

clean:		
			echo "\tremoving files..."
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

.SILENT: