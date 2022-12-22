# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 10:34:24 by ysensoy           #+#    #+#              #
#    Updated: 2022/12/22 17:08:44 by mtemel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CLAFGS = -Wall -Wextra -Werror
SRCS = *.c
OBJ = $(SRCS:.c=.o)

all: yasin

yasin :
	$(CC) $(CLAFGS) $(SRCS) -lreadline -L /Users/yasinsensoy/homebrew/opt/readline/lib -I /Users/yasinsensoy/homebrew/opt/readline/include -o $(NAME)
	@echo "\033[1;92mderlendi..\033[0m"
clean:
	@rm -rf minishell
