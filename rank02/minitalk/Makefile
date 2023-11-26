# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 10:29:53 by alopez-g          #+#    #+#              #
#    Updated: 2022/07/06 23:40:00 by alopez-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[0;31m
CYAN = \033[0;36m
GREEN = \033[1;32m
YELLOW = \033[1;33m
NC = \033[0m

NAME = minitalk
SERVER = server
CLIENT = client
DIR = .
I_DIR = $(DIR)/includes
I_CLIENT_DIR = $(I_DIR)/$(CLIENT)
I_SERVER_DIR = $(I_DIR)/$(SERVER)
I_COMMON = $(I_DIR)/common.h $(I_DIR)/msg.h

SRC_DIR = $(DIR)/src
SRC_CLIENT = $(SRC_DIR)/client.c
SRC_SERVER = $(SRC_DIR)/server.c
SRC_COMMON = $(SRC_DIR)/libft_utils.c $(SRC_DIR)/msg.c
SRC = $(patsubst %.c, $(DIR)/%.c, $(SRC_COMMON) $(SRC_CLIENT) $(SRC_SERVER))

OBJ_CLIENT = $(patsubst %.c, %.o, $(SRC_CLIENT))
OBJ_SERVER = $(patsubst %.c, %.o, $(SRC_SERVER))
OBJ_COMMON = $(patsubst %.c, %.o, $(SRC_COMMON))
OBJ = $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_COMMON)

CC = gcc
FLAGS = -Wall -Wextra -Werror
I = -I $(I_DIR)/ -I $(I_CLIENT_DIR)/ -I $(I_SERVER_DIR)/
%.o : %.c
	@$(CC) $(FLAGS) $(I) -c $< -o $@

all: $(NAME)
$(NAME): $(CLIENT) $(SERVER)
$(CLIENT): $(OBJ_CLIENT) $(OBJ_COMMON) $(I_CLIENT) $(I_COMMON)
	@$(CC) $(FLAGS) $(OBJ_CLIENT) $(OBJ_COMMON) -o client
	@echo "$(GREEN)Client ready!$(NC)"
$(SERVER): $(OBJ_SERVER) $(OBJ_COMMON) $(I_SERVER) $(I_COMMON)
	@$(CC) $(FLAGS) $(OBJ_SERVER) $(OBJ_COMMON) -o server
	@echo "$(GREEN)Server ready!$(NC)"
clean:
	@rm -rf $(OBJ)
	@echo "$(RED)Objs removed$(NC)"
fclean: clean
	@rm -rf $(SERVER)
	@rm -rf $(CLIENT)
	@echo "$(RED)Executables removed$(NC)"
re: fclean	$(NAME)
.PHONY: clean fclean re
fast: FLAGS = -Wall -Wextra -Werror -O3
fast: re
