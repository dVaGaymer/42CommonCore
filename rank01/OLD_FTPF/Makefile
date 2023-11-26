# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmartin- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/27 00:11:59 by mmartin-          #+#    #+#              #
#    Updated: 2020/02/29 19:08:29 by alopez-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
PRINT_D	= srcs 
PRINT_I	= includes
LIBFT_D	= srcs/libft
LIBFT_I	= includes
SRCS	= $(shell find $(PRINT_D) -type f -name "*.c" ! -name "*_bonus.c")
OBJS	= ${SRCS:.c=.o}
NAME	= libftprintf.a
%.o : %.c
			@clang -I $(PRINT_I) -I $(LIBFT_I) -c $< -o $@
$(NAME):	$(OBJS)
			@make -s -C $(LIBFT_D) bonus
			@echo ">>> Dependency 'libft' is ready"
			@cp $(LIBFT_D)/libft.a $(NAME)
			@echo ">>> Compiling 'libftprintf'"
			@ar -rcs $(NAME) ${OBJS}
			@ranlib $(NAME)
			@echo ">>> Library 'libftprintf' is ready to use"
all:		$(NAME)
clean:
			@make -s -C $(LIBFT_D) clean
			@rm -f $(OBJS)
fclean:		clean
			@make -s -C $(LIBFT_D) fclean
			@rm -f $(NAME)
re:			fclean all
.PHONY:		all clean fclean re
