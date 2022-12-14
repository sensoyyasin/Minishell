#include "minishell.h"

int		heredoc_cnt()
{
	t_list *iter;

	iter = shell->arg;
	shell->heredoc = 0;
	while (iter != NULL)
	{
		if (ft_strcmp(iter->content, "<<") && !ft_strcmp(iter->content, ">>"))
			shell->heredoc++;
		iter = iter->next;
	}
	return(shell->heredoc);
}

int		heredoc_list()
{
	t_list *iter;
	int		i;

	i = 0;
	iter = shell->arg;
	while (iter != NULL)
	{
		if (ft_strcmp(iter->content, "<<"))
			return(i);
		i++;
		iter = iter->next;
	}
	return(0);
}

void deneme(int a)
{
	exit(a);
}
void	heredoc_functions()
{
	int a;

	if (fork()==0)
	{
		signal(SIGINT, (void *)exit);
		heredoc_f();
		exit(0);
	}
	waitpid(-1, &a, 0);
	if (a != 0)
		return ;
	cut_heredoc(); /*-> << ve heredoc'a giren kelimeyi cutlamamız lazım echo kalacak.*/
	run_cmd_heredoc();
}

/* delete all list expect first line */
void	cut_heredoc()
{
	t_list *first;
	t_list *current;
	t_list *next;

	first = shell->arg;
	if (!first)
		return ;
	current = first->next;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	first->next = NULL;
	/* while (shell->arg)
	{
		printf("shell content: %s\n",shell->arg->content);
		shell->arg = shell->arg->next;
	}
	while (first)
	{
		printf("first content: %s\n",first->content);
		first = first->next;
	} */

}
/* start readline till eof occured */
void	heredoc_f()
{
	char	*str;
	char	*eof;
	int		fd;


	eof = index_data(shell->arg, heredoc_list() + 1);
	fd = open(".heredoc", O_WRONLY | O_CREAT | O_TRUNC);

	if (fd < 0)
		write(2, "Error\n", 6);
	else
	{

		while (1)
		{
			str = readline("> ");
			if (!str)
				break;
			/* signal(SIGINT, (void *)exit);
			signal(SIGQUIT, SIG_IGN); */
			if (ft_strcmp(str, eof)) // str == eof olamaz adreslerini kıyaslıyorum pointer oldukları icin.
				break;
			/* printf("while sonu\n"); */
			ft_putstr_fd(str, fd);
			ft_putstr_fd("\n", fd);
		}
		free(str);
	}
	close(fd);
	return ;
}

/* create a child process and execute the command */
void	run_cmd_heredoc()
{
	int	pid;
	int	fd;


	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, deneme);
		//signal(SIGQUIT, SIG_IGN);
		fd = open(".heredoc", O_RDWR);
		if (fd < 0)
			write(2, "Error\n", 6);
		dup2(fd, 0);
		close(fd);
		executor();
		exit(0);
	}
	if (pid > 0)
		printf("%d\n", getpid());
	waitpid(pid, NULL, 0);
}
