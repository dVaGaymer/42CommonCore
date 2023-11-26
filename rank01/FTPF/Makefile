# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/07 17:46:30 by alopez-g          #+#    #+#              #
#    Updated: 2020/08/10 00:15:54 by alopez-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FTPF_INC	=	${FTPF_DIR}includes/
LIBFT_INC	=	${LIBFT_DIR}includes/

SRCS_DIR	=	${FTPF_DIR}srcs/
SRCS		=	${SRCS_DIR}ft_printf.c ${SRCS_DIR}struct_utils.c ${SRCS_DIR}ft_printf_utils.c \
			${SRCS_DIR}c_flags.c ${SRCS_DIR}d_flags.c ${SRCS_DIR}u_flags.c ${SRCS_DIR}s_flags.c ${SRCS_DIR}p_flags.c \
			${SRCS_DIR}apply_utils.c ${SRCS_DIR}x_flags.c
OBJS		= 	$(patsubst %.c, %.o, ${SRCS})

NAME		=	libftprintf.a

%.o : %.c
				clang -Wall -Werror -Wextra -I $(FTPF_INC) -I $(LIBFT_INC) -c $< -o $@

${NAME}:		${OBJS}
				ar -rc ${NAME} ${OBJS}
				ar -s ${NAME}
				
all:			${NAME}
bonus:			all
clean:
				rm -f ${OBJS} ${OBJS_BONUS}
fclean:			clean
				rm -f ${NAME}
re:				fclean all
.PHONY:			all clean fclean re bonus
