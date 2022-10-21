NAME = minishell
CC = gcc
CLAFGS = -Wall -Wextra -Werror
SRC = *.c
OBJ = $(SRC:.c=.o)

all: yasin

yasin :
	$(CC) $(CLAFGS) $(SRC) -lreadline -L /goinfre/homebrew/opt/readline/lib -I /goinfre/homebrew/opt/readline/include -o $(NAME)
	@echo "derlendi.."
clean:
	@rm -rf minishell
