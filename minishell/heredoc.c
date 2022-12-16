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

int		redirect_cnt()
{
	t_list	*iter;

	iter = shell->arg;
	while (iter != NULL)
	{
		if (ft_strcmp(iter->content, ">>"))
		{
			shell->right_double_counter++;
			return(shell->right_double_counter);
		}
		iter = iter->next;
	}
	return (0);
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

void pro_fork(int i)
{
	shell->fpid = 1;
	exit(i);
}

void	heredoc_functions()
{
	int a;

	shell->fpid = fork();
	if (shell->fpid == 0)
	{
		signal(SIGINT, pro_fork);
		heredoc_f();
		cut_heredoc(); /*-> << ve heredoc'a giren kelimeyi cutlamamız lazım echo kalacak.*/
		run_cmd_heredoc();
		exit(0);//burası çok önemli
	}
	waitpid(-1, &a, 0);
	if (a != 0)
		return ;
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
}

/* start readline till eof occured */
void	heredoc_f()
{
	char	*str;
	char	*eof;
	int		fd;

	if (shell->fpid == 0)
	{
		eof = index_data(shell->arg, heredoc_list() + 1);
		fd = open(".heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd < 0)
			write(2, "Error\n", 6);
		else
		{
			while (1)
			{
				str = readline("> ");
				if (!str)
					break;
				if (ft_strcmp(str, eof)) // str == eof olamaz adreslerini kıyaslıyorum pointer oldukları icin.
					break;
				ft_putstr_fd(str, fd);
				ft_putstr_fd("\n", fd);
			}
			free(str);
		}
		close(fd);
	}
	return ;
}

/* create a child process and execute the command */
void	run_cmd_heredoc()
{
	//int	pid;
	int	fd;

	if (shell->fpid == 0)
	{
		fd = open(".heredoc", O_RDWR);
		if (fd < 0)
			write(2, "Error\n", 6);
		dup2(fd, 0);
		close(fd);
		executor();
		exit(0);
	}
}

void	single_right_redirection()
{
	int		fd;
	char	*str;

	str = index_data(shell->arg, single_right_redirect_list() + 1);
	fd = open(str, O_CREAT | O_APPEND | O_RDWR, 0777);
	if (fd < 0)
		write(2, "Error\n", 6);
	dup2(fd, STDOUT_FILENO);
	cut_heredoc();
	close(fd);
	executor();
}

int		single_right_redirect_list()
{
	t_list	*iter;
	int		i;

	i = 0;
	iter = shell->arg;
	while (iter != NULL)
	{
		if (ft_strcmp(iter->content, ">>"))
			return(i);
		i++;
		iter = iter->next;
	}
	return(0);
}
