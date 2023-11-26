NAME		=	megaphone

#----- SRC ----
SRC_DIR	=	.
SRC		=	$(SRC_DIR)/megaphone.cpp

#----- OBJ -----
OBJ		=	$(SRC:.cpp=.o)

#----- FLAGS -----
CC			=	c++
C_FLAGS		=	-std=c++98 -Wall -Wextra -Werror

#----- IMPICIT RULES -----
$(addprefix $(SRC_DIR)/, %.o):	$(addprefix $(SRC_DIR)/, %.cpp)
	$(CC) $(C_FLAGS) -c $< -o $@

#----- RULES
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(C_FLAGS) $(OBJ) -o $@

clean:
	$(RM) -rf $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

n:
	norminette

.PHONY: clean fclean re all

#----- UTILS -----
RED				=	\033[0;31m
CYAN			=	\033[0;36m
GREEN 			=	\033[1;32m
YELLOW 			=	\033[1;33m
NC 				=	\033[0m
