# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 14:55:43 by msoria-j          #+#    #+#              #
#    Updated: 2023/11/14 15:11:38 by msoria-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** # 
#                                                                              # 
# $< = First prerequisite name - in this case, in $(SRC)                       # 
# $@ = Name of the target (each file .o)                                       # 
# gcc: -c compiles each source into a .o file, to be linked later on           # 
# gcc: -o specifies the name of the executable                                 # 
#                                                                              # 
# Change CPPFLAGS to CFLAGS, c++ to gcc and OBJFLAGS according to need         # 
#                                                                              # 
# **************************************************************************** # 

SRC			=	main.cpp \
				ClapTrap.cpp \
				ScavTrap.cpp \

CPPFLAGS	=	-Wall -Wextra -Werror -pedantic -std=c++98 -ggdb
OBJFLAGS	=	-Wall -Wextra -Werror -pedantic -std=c++98 -ggdb
CC			=	c++ 
NAME		=	scavtrap
OBJ			=	$(SRC:.cpp=.o) 

%.o:		%.cpp 
			$(CC) $(OBJFLAGS) -c $< -o $@ 
			
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
