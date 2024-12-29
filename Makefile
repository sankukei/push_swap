# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leothoma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/27 14:55:10 by leothoma          #+#    #+#              #
#    Updated: 2024/12/27 14:55:10 by leothoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

COMP = cc

FLAGS = -Wall -Wextra -Werror -g3 -I ./

SRC =	main.c \
	utils.c \

OBJS = ${SRC:.c=.o}

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

${NAME}: ${OBJS}
	 cd libft && make && make bonus && cd ../ && $(CC) ${OBJS} -Llibft -lft -o $(NAME) && rm *.o

all: ${NAME}

clean:
	rm -f ${OBJS} 

fclean: clean;
	rm -f push_swap

re: fclean all
		
.PHONY: all, clean, fclean, re, bonus
