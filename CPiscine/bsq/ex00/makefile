SRCS	= main.c ft_checking.c ft_format.c ft_load_map.c ft_solve_map.c ft_show_map.c 

OBJS	= ${SRCS:.c=.o}

NAME	= BSQ

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
