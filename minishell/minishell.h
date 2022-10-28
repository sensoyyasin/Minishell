#ifndef MINISHELL
# define MINISHELL

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
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
	char 		**str;
	char		**str_pipe;
	char		**temp_env;

	int			pipe;
	int			quote;
	int 		pid;
}		t_shell;


typedef struct a_list
{
	void			*content;
	struct	t_list	*next;
}	t_list;

char	prompt(char *str);
int		ft_echo(t_shell *shell, int i);
char	*path_finder();
int		ft_pwd(void);
char	**ft_split(char *ptr, char c);
int		ft_exit(int i);
int		ft_strlen(const char *str);
int		ft_strcmp(char *str1,char *str2);
char	*ft_strjoin(char const *s1, char const *s2);
int		check(t_shell *shell);
int		ft_strncmp(char *str1, char *str2, size_t n);
int		ft_cd(t_shell *shell);
void	handle_siginit(int sig);
int		other_cmnds(char **arg);
char	*to_lower(char *str);
void	shell_pipe_dup2(t_shell *shell);
void	pipe_sayici(t_shell *shell);
void	multi_close(int **fd);
int 	check2(t_shell *shell, int i);
void	quote_sayici(t_shell *shell);
void	handle_siginit(int sig);


void	ft_lstadd_back(t_list **lst, t_list *new);
void	*ft_lstlast(t_list *lst);

#endif
