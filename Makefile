# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 16:43:20 by dda-silv          #+#    #+#              #
#    Updated: 2014/11/05 18:55:13 by dda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = ../libft/ft_*.c

all: test

test:
	norminette $(SRC)
	$(CC) $(CFLAGS) runner.c test_macros.c tests.c $(SRC) -o test_runner
	./test_runner
	rm test_runner
