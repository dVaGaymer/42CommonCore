# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/01 21:30:15 by alopez-g          #+#    #+#              #
#    Updated: 2020/02/29 19:26:26 by alopez-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:
MAIN		= ../debug/main.c
SRCDIR		= ../srcs/
LIBFTSRCDIR	= ../srcs/libft/

UTILSRC		= $(wildcard ${SRCDIR}*.c)
UTILOBJS	= $(patsubst %.c, %.o, $(UTILSRC))

LIBFTSRC	= $(wildcard ${LIBFTSRCDIR}*.c)
LIBFTOBJS	= $(patsubst %.c, %.o, $(LIBFTSRC))

NAME		= PF

$(NAME):	${UTILOBJS} ${LIBFTOBJS}
			clang -Wall -Wextra ${MAIN} ${UTILOBJS} ${LIBFTOBJS} -o ${NAME}
			echo "\033[1;32mDONE"
all:		${NAME}
clean:
			echo "\033[1;31mCLEANED"
			rm -f $(OBJ) ${UTILOBJS} ${LIBFTOBJS}
fclean:		clean
			rm -f ${NAME}
re:			fclean all
