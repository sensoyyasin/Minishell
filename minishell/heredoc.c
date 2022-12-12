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

void	heredoc_functions()
{
	t_list	*iter;

	iter = shell->arg;
	heredoc_f();
	if (shell->heredoc == 1)
	{
		run_cmd_heredoc();
		shell->heredoc--;
	}
	else
		shell->heredoc--;
	if (shell->heredoc == 0)
		return ;
	if (!ft_lstcmp(iter, "<<"))
		heredoc_functions(); 
	//heredoc_f();
	//cut_heredoc(); /*-> << ve heredoc'a giren kelimeyi cutlamamız lazım echo kalacak.*/
	//run_cmd_heredoc();
}

void	cut_heredoc()
{
	t_list	*temp;
	t_list	*temp2;

	temp = shell->arg;
	temp2 = shell->arg;
	if (temp == NULL)
	{
		free(temp);
		return ;
	}
	while (temp != NULL)
	{
		temp2 = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return ;
	temp2->next = temp->next;
	free(temp);
}

void	heredoc_f()
{
	char	*str;
	char	*eof;
	int		fd;

	eof = index_data(shell->arg, heredoc_list() + 1);
	fd = open("a.txt", O_WRONLY | O_CREAT | O_TRUNC);
	if (fd < 0)
		write(2, "Error\n", 6);
	else
	{
		while (1)
		{
			str = readline("> ");
			signal(SIGINT, handle_siginit);
			signal(SIGQUIT, SIG_IGN);
			if (ft_strcmp(str, eof)) // str == eof olamaz adreslerini kıyaslıyorum pointer oldukları icin.
				break;
			ft_putstr_fd(str, fd);
			ft_putstr_fd("\n", fd);
		}
		free(str);
	}
	close(fd);
	return ;
}

void	run_cmd_heredoc()
{
	int	pid;
	int	fd;

	pid = fork();
	while (pid >= 0)
	{
		fd = open("a.txt", O_RDWR);
		if (fd < 0)
			write(2, "Error\n", 6);
		dup2(fd, 0);
		close(fd);
		executor();
		exit(0);
	}
	wait(NULL);
	waitpid(pid, NULL, 0);
}
