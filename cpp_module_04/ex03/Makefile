# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 21:16:24 by msoria-j          #+#    #+#              #
#    Updated: 2023/11/21 11:52:59 by msoria-j         ###   ########.fr        #
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
				AMateria.cpp \
				Ice.cpp \
				Cure.cpp \
				Character.cpp \
				MateriaSource.cpp \

CPPFLAGS	=	-Wall -Wextra -Werror -pedantic -std=c++98 -g -O0
OBJFLAGS	=	-Wall -Wextra -Werror -pedantic -std=c++98 -g -O0
CC			=	c++ 
NAME		=	materia
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

# .SILENT: 
