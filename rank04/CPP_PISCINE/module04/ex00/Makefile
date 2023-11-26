NAME		=	animal

#----- HEADER -----
H_DIR	=	include
H		=	$(H_DIR)/Animal.hpp \
			$(H_DIR)/Dog.hpp \
			$(H_DIR)/Cat.hpp \
			$(H_DIR)/WrongCat.hpp \
			$(H_DIR)/WrongAnimal.hpp

#----- SRC ----
SRC_DIR	=	src
SRC		=	$(SRC_DIR)/main.cpp \
			$(SRC_DIR)/Animal.cpp \
			$(SRC_DIR)/Dog.cpp \
			$(SRC_DIR)/Cat.cpp \
			$(SRC_DIR)/WrongCat.cpp \
			$(SRC_DIR)/WrongAnimal.cpp
			
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
