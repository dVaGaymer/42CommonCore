NAME		=	fragTrap

#----- HEADER -----
H_DIR	=	include
H		=	$(H_DIR)/ClapTrap.hpp \
			$(H_DIR)/ScavTrap.hpp \
			$(H_DIR)/FragTrap.hpp


#----- SRC ----
SRC_DIR	=	src
SRC		=	$(SRC_DIR)/main.cpp \
			$(SRC_DIR)/ClapTrap.cpp \
			$(SRC_DIR)/ScavTrap.cpp \
			$(SRC_DIR)/FragTrap.cpp

#----- OBJ -----
OBJ		=	$(SRC:.cpp=.o)

#----- FLAGS -----
CC			=	c++
H_FLAGS		=	-I$(H_DIR)
C_FLAGS		=	-std=c++98 -Wall -Wextra -Werror
LIB_FLAGS	=

#----- IMPICIT RULES -----
$(addprefix $(SRC_DIR)/, %.o):	$(addprefix $(SRC_DIR)/, %.cpp) $(H)
	$(CC) $(H_FLAGS) $(C_FLAGS) -c $< -o $@

#----- RULES
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(H_FLAGS) $(LIB_FLAGS) $(OBJ) -o $@

clean:
	$(RM) -rf $(OBJ)

fclean: clean
	$(RM) -rf $(OBJ)
	$(RM) $(NAME)

re: fclean all

n:
	norminette

#----- UTILS -----
RED				=	\033[0;31m
CYAN			=	\033[0;36m
GREEN 			=	\033[1;32m
YELLOW 			=	\033[1;33m
NC 				=	\033[0m

.PHONY: clean fclean re all
