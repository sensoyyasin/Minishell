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
#include <fcntl.h>

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
	t_list	*declare;
	t_list	*cmd;
	t_list	*arg;
	t_list	*pipe_arg;
	t_list	*token;
	int	step;
	int	ctrl;
	int	s_quote;
	int	d_quote;
	int	right_single_counter;
	int	right_double_counter;
	int	left_single_counter;
	int	pipe;
	int	cmmp;
	int	len;
	int	heredoc;
	int	exit_status;
	int	saved_stdout;
	int	fd;
}	t_shell;

t_shell	*shell;

void	delete_node(t_list **head, char *str);
int		isnamequal(char *str, char *content);
int		islistequal(char *str);
int		isequal(char *str);
int		uisnamequal(char *str, char *content);
void	udelete_node(t_list **head, char *str);

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
int		lstcmp_isequal(char *str);
int		ft_lstcmp(t_list *iter, char *str);
char	**ft_split(char	*ptr, char c);
void	free_list(void);
void	ft_putstr_fd(char *str, int fd);
void	reset_stdout();

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
void	other_commands(char **arg);
char	**list_changed(t_list *list);
int		ft_isalpha(char *str);

// -> pipe
void	shell_pipe_dup2();
void	multi_close(int **fd);
int		check2(int i);
int		ft_strcmp2(char *asd, char *sda);
void	ft_dstry_node();
void	ft_lstremover(t_list *list);
void	check_cmnd2();

// -> heredoc
int		heredoc_cnt();
void	heredoc_f();
void	run_cmd_heredoc();
int		heredoc_list();
void	heredoc_functions();
void	cut_heredoc();

// -> redirections
int		index_redirect(char *str);
int		redirections_counter();

#endif
