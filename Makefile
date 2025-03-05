NAME = push_swap

COMP = cc

FLAGS = -Wall -Wextra -Werror -g3 -I ./

SRC =	main.c \
	utils.c \
	list_utils.c \
	utils.c \
	sort_functions.c \

OBJS = ${SRC:.c=.o}

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

${NAME}: ${OBJS}
	$(CC) ${OBJS} ${FLAGS} -o $(NAME) && rm *.o

all: ${NAME}

clean:
	rm -f ${OBJS} 

fclean: clean;
	rm -f push_swap

re: fclean all
		
.PHONY: all, clean, fclean, re, bonus