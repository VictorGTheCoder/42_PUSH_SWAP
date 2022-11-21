SRCS = utils.c utils_2.c sort_utils.c push_and_pop.c main.c

CC = gcc

FLAGS = -Werror -Wall -Wextra -fsanitize=address 

OBJS = ${SRCS:.c=.o}

NAME = push_swap

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${FLAGS} -o ${NAME} ${OBJS} -L. -lft

all: ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re