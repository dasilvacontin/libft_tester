# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 16:43:20 by dda-silv          #+#    #+#              #
#    Updated: 2014/11/08 19:31:30 by dda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC_DIR = ../libft

all: blank norm test

blank:
	clear
	clear

norm:
	! norminette $(SRC_DIR)/ft_*.c $(SRC_DIR)/*.h | egrep -B1 -i "Error|Warning"

test:
	$(CC) $(CFLAGS) runner.c test_macros.c tests.c $(SRC_DIR)/ft_*.c -o test_runner
	./test_runner
	rm test_runner
