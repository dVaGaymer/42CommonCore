NAME		=	serialization

#----- HEADER -----
H_DIR	=	include
H		=	$(H_DIR)/

#----- SRC ----
SRC_DIR	=	src
SRC		=	$(SRC_DIR)/main.cpp \
			$(SRC_DIR)/Serializer.cpp

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

.PHONY: clean fclean re all
