# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 10:34:24 by ysensoy           #+#    #+#              #
#    Updated: 2022/12/27 15:23:33 by mtemel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell.a
CC = gcc
CLAFGS = -Wall -Wextra -Werror
SRCS = (*.c ./built-in/*.c ./check_token/*.c ./executor/*.c ./expand/*.c ./functions/*.c ./heredoc/*.c
	./lexer/*.c ./list/*.c ./pipe/*.c ./redirections/*.c)
OBJ = $(SRCS:.c=.o)

$(NAME):
	$(CC) $(CLAFGS) $(OBJ) -o $(NAME) -lreadline -L /Users/yasinsensoy/homebrew/opt/readline/lib -I /Users/yasinsensoy/homebrew/opt/readline/include
	@echo "\033[1;92mCompile..\033[0m"

all: $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
