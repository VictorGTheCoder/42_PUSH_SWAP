SRCS = utils.c utils_2.c utils_3.c sort_utils.c sort_utils_2.c sort_utils_3.c short_sort.c push_and_pop.c main.c sort.c quick_sort.c strjoin.c 

CC = gcc -fsanitize=address 

FLAGS = -Werror -Wall -Wextra

OBJS = ${SRCS:.c=.o}

NAME = push_swap

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${FLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re