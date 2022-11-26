# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 10:34:24 by ysensoy           #+#    #+#              #
#    Updated: 2022/11/21 11:37:46 by ysensoy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CLAFGS = -Wall -Wextra -Werror
SRCS = *.c
OBJ = $(SRCS:.c=.o)

all: yasin

yasin :
	$(CC) $(CLAFGS) $(SRCS) -lreadline -L /goinfre/homebrew/opt/readline/lib -I /goinfre/homebrew/opt/readline/include -o $(NAME)
	@echo "derlendi.."
clean:
	@rm -rf minishell