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

char **environ;

typedef struct s_list
{
	void			*content;
	void			*data;
	struct s_list	*next;
}	t_list;

typedef struct s_shell
{
	char 		**str;
	char		**str_pipe;
	char		**temp_env;
	char		*temp;
	t_list		*x;

	int			len;
	int			heredoc;
	int			quote;
	int			pipe;
	int			sayi;
	int 		pid;
}		t_shell;

t_shell *shell;

char	prompt(char *str);
int		ft_echo(t_shell *shell, int i);
char	*path_finder();
int		ft_pwd(void);
char	**ft_split(char *ptr, char c);
int		ft_exit(int i);
int		ft_strcmp(char *str1,char *str2);
char	*ft_strjoin(char const *s1, char const *s2);
int		check(t_shell *shell);
int		ft_cd(t_shell *shell);
void	handle_siginit(int sig);
char	*to_lower(char *str);
void	shell_pipe_dup2(t_shell *shell);
void	pipe_sayici();
void	multi_close(int **fd);
int 	check2(t_shell *shell, int i);
void	quote_sayici();
void	handle_siginit(int sig);
int		other_cmnds(char **arg);

int		ft_strncmp(char *str1, char *str2, size_t n);
char	*to_lower(char *str);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_itoa(int n);

void	ft_env(void);

void	ft_export(t_shell *shell);
void	fill(t_shell *shell);

void	ft_unset(t_shell *shell);
void	ft_remover(t_shell *shell, int counter);

t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstnew(void	*content);
void		ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
char		*ft_strchr(char *s, int c);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

void	quote_sayici();
int		size_dquote_dollar(t_shell *shell);
int		size_dquote(t_shell *shell);
int		find_size(t_shell *shell);
char	*expand_quote(t_shell *shell);
char	*final_line(t_shell *shell);
int		size_squote(t_shell *shell);
char	*d_quote(t_shell *shell, int i, int j);
char	*s_quote(t_shell *shell, int i, int j);
char	*dollar_sign(t_shell *shell, char *str, int j);

char	*check_env();
char	*ret_env(int i, char *str);

#endif
