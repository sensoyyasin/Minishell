#ifndef MINISHELL_H
#define MINISHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>
#include <stdbool.h>
#include <signal.h>

# define DEFAULT "\033[0;39m"
# define GRAY "\033[0;90m"
# define RED "\033[0;91m"
# define GREEN "\033[0;92m"
# define YELLOW "\033[0;93m"
# define BLUE "\033[0;94m"
# define MAGENTA "\033[0;95m"
# define CYAN "\033[0;96m"
# define WHITE "\033[0;97m"

typedef struct s_list
{
	char			*content;
	void			*data;
	struct s_list	*next;
}	t_list;

typedef struct s_shell
{
	char	*line;
	char	*name;

	char **environ;
	char 	**str;
	char	**str_pipe;
	char	*temp;
	t_list	*asd;
	t_list	*cmd;
	t_list	*arg;
	t_list	*token;
	int	ctrl;
	int	s_quote;
	int	d_quote;
	int	pipe;
	int	cmmp;
	int	len;
	int	exit_status;
	int	fd;
}	t_shell;

t_shell	*shell;

void	sighandler(int signum);
void	signal_d();
int		normal(void);
void	appointment(char **env);
int		is_cmd(char	*str);
//lexer
void    here_doc(int i);
void 	lexer(void);
void	space_skip(void);
void	lexur(int cnt);
int		text_cmpr(void);
int		token_compr(void);
int		cmnd_length(void);
int		ft_strcmp(char *asd, char *sda);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
#endif
