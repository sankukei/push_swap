# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leothoma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 14:38:40 by leothoma          #+#    #+#              #
#    Updated: 2025/03/06 14:38:41 by leothoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

COMP = cc

FLAGS = -Wall -Wextra -Werror -g3 -I ./

SRC =	main.c \
	list_utils.c \
	sort_functions.c \
	sort_function2.c \
	sort_functions3.c \
	radix.c \
	ft_split.c \
	get_stack_size.c \
	utils.c \
	list_utils2.c \
	parsing.c \
	parsing2.c \


OBJS = ${SRC:.c=.o}

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

${NAME}: ${OBJS}
	$(CC) ${OBJS} ${FLAGS} -o $(NAME)

all: ${NAME}

clean:
	rm -f ${OBJS} 

fclean: clean;
	rm -f push_swap

re: fclean all
		
.PHONY: all, clean, fclean, re, bonus
