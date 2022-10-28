NAME = minishell
CC = gcc
CLAFGS = -Wall -Wextra -Werror
SRCS = *.c
OBJ = $(SRC:.c=.o)

all: yasin

yasin :
	$(CC) $(CLAFGS) $(SRCS) -lreadline -L /goinfre/homebrew/opt/readline/lib -I /goinfre/homebrew/opt/readline/include -o $(NAME)
	@echo "derlendi.."
clean:
	@rm -rf minishell
