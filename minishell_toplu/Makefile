# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 10:34:24 by ysensoy           #+#    #+#              #
#    Updated: 2022/12/27 16:35:19 by mtemel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CLAFGS = -Wall -Wextra -Werror
SRCS = $(wildcard *.c built-in/*.c check_token/*.c executor/*.c expand/*.c functions/*.c \
		heredoc/*.c lexer/*.c list/*.c pipe/*.c redirections/*.c)
OBJ = $(SRCS:.c = .o)

$(NAME): $(OBJ)
	@$(CC) $(CLAFGS) $(SRCS) -lreadline -L /Users/yasinsensoy/homebrew/opt/readline/lib -I /Users/yasinsensoy/homebrew/opt/readline/include -o $(NAME)
	@echo "\033[1;92mCompiled succesfully..\033[0m"

all: $(NAME)

clean:
	rm -rf  $(NAME)

fclean: clean
	rm -rf .heredoc

re: fclean all

.PHONY: all clean fclean re
