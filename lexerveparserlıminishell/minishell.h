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

#define D_QUOTE 34
#define	S_QUOTE 39

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
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_shell
{
	char	*line;
	char	*name;

	char	**environ;
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
void	ft_fill();
int		is_cmd(char	*str);
//lexer
void    here_doc(int i);
int 	lexer(void);
void	space_skip(void);
void	lexur(int cnt);
int		text_cmpr(void);
int		token_compare(void);
int		cmnd_length(void);


int		ft_strcmp(char *str, char *str2);
char	*ft_strchr(const char *s, int x);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	signal_d(void);
void	handle_siginit(int sig);
//functions - utils
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strncmp(char *str1, char *str2, size_t n);
char	*ft_strdup(char *s1);
int		ft_listsize(t_list *list);
t_list	*ft_lstnew(void *content);
int		lstcmp(char *str);
int		ft_strcmp_z(char *str, char *str2);
char    **ft_split(char	*ptr, char c);
void	free_list(void);

// -> expander
void	expander();
void	expand(int index);
t_list	*list_f_data(t_list *root, int index);
void	s_quote(int index);
void	d_quote(int index);
char	*index_data(t_list *list, int index);
char	*dollar_sign(char *str, int j);
int		quote_check(char *str);

char	*ret_env(int i, char *str);
char	*check_env(void);
int		size_finder(char *str, int j);

// -> executor
void	executor();
int		pipe_stat();

// -> run_cmd
void	run_cmd_without_pipe(t_list *list);
void	run_cmd_with_pipe();

// -> cmnds
void	ft_echo(t_list *list);
void	ft_export(t_list *list);
int		ft_env(void);
void	ft_pwd(void);
void	ft_unset(t_list *list);
void	printf_alph(void);
void	ft_pipe_counter();
void	ft_pipe_func();
void	ft_lstclear(t_list *lst);

// -> other commands
void    other_commands(char **arg);
char    **list_changed(t_list *list);

#endif
