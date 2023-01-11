/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:57:23 by mtemel            #+#    #+#             */
/*   Updated: 2023/01/11 12:32:25 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <time.h>
# include <stdbool.h>
# include <signal.h>
# include <fcntl.h>

# define D_QUOTE 34
# define S_QUOTE 39

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
	struct s_list	*next;
}	t_list;

typedef struct s_g_shell
{
	char	*line;
	char	*name;
	char	*my_content;

	char	**environ;
	char	**str;
	char	**str_pipe;
	char	*temp;
	char	*iter;
	t_list	*asd;
	t_list	*cmd;
	t_list	*arg;
	t_list	*pipe_arg;
	t_list	*token;
	int		step;
	int		ctrl;
	int		s_quote;
	int		d_quote;
	int		right_single_counter;
	int		right_double_counter;
	int		left_single_counter;
	int		pipe;
	int		cmmp;
	int		len;
	int		heredoc;
	int		exit_status;
	int		saved_stdout;
	int		fd;
	int		fpid;
}	t_g_shell;

t_g_shell	*g_shell;

void	delete_node(t_list **head, char *str);
int		isnamequal(char *str, char *content);
int		islistequal(char *str);
int		isequal(char *str);
int		uisnamequal(char *str, char *content);
void	udelete_node(t_list **head, char *str);
void	pro_fork(int i);
char	*find_env(char *str);

void	sighandler(int signum);
void	signal_d(void);
int		normal(void);
void	appointment(char **env);
void	ft_fill(void);
int		is_cmd(char	*str);
//lexer
void	here_doc(int i);
int		lexer(void);
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
int		lstcmp_isequal(char *str);
int		ft_lstcmp(t_list *iter, char *str);
char	*ft_substr(char *s, int start, int len);
char	**ft_split(char *s, char c);
void	free_list(void);
void	free_p_list(void);
void	ft_putstr_fd(char *str, int fd);
char	*ft_itoa(int n);

// -> expander
void	expander(void);
void	expand(int index);
t_list	*list_f_data(t_list *root, int index);
void	s_quote(int index);
void	d_quote(int index);
char	*index_data(t_list *list, int index);
char	*dollar_sign(char *str, int j);
int		quote_check(char *str);

char	*ret_env(int i, char *str);
char	*check_env(void);
char	*ft_str_eq_dup(char *s1);
int		size_finder(char *str, int j);
int		checker_tkn(char *str);
void	free_str(char **ret_dolar);

// -> executor
void	executor(void);
int		pipe_stat(void);

// -> run_cmd
void	run_cmd_without_pipe(t_list *list);
void	run_cmd_with_pipe(void);

// -> cmnds
void	ft_echo(t_list *list);
void	ft_export(t_list *list);
int		ft_env(void);
void	ft_pwd(void);
void	ft_unset(t_list *list);
void	printf_alph(void);
void	ft_pipe_counter(void);
void	ft_pipe_func(void);
void	ft_lstclear(t_list *lst);

// -> other commands
void	other_commands(char **arg);
char	**list_changed(t_list *list);
int		ft_isalpha(char *str);

// -> pipe
void	g_shell_pipe_dup2(void);
void	multi_close(int **fd);
int		check2(int i);
int		ft_strcmp2(char *asd, char *sda);
void	ft_dstry_node(void);
void	ft_lstremover(t_list *list);
void	check_cmnd2(void);
void	fd_opener(int *i, int **fd);
void	fd_checker(int *i, int ***fd);
void	fork_work(int **fd);
void	big_pipe(int *i, int **fd);

// -> heredoc
int		heredoc_cnt(void);
void	heredoc_f(void);
void	run_cmd_heredoc(void);
int		heredoc_list(void);
void	heredoc_functions(void);
void	cut_heredoc(void);
void	hdelete_node(t_list **head, char *str);
int		hisnamequal(char *str, char *content);
void	heredoc_f2(char **str, char **eof, int *fd);

// -> redirections
int		index_redirect(char *str);
int		redirect_cnt(void);
int		redirections_counter(void);
int		double_right_redirect_list(void);
void	double_right_redirection(void);
void	double_right_redirection2(int *fd, char **str);
int		single_right_redirect_list(void);
void	single_right_redirection(void);
void	single_right_redirection2(int *fd, char **str);
int		single_left_redirect_list(void);
void	single_left_redirection(void);
void	single_right_redirection2(int *fd, char **str);
int		check_token(void);
int		checker_tkn(char *str);

// ->cd
char	*tail_trimer(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
void	ft_cd2(char *pwd);
int		ft_cd(t_list *list);
void	ft_exit(t_list *list);
void	ft_cd_norm(char **pwd, char **a);

#endif
