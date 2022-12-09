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

void	heredoc_f()
{
	char	*str;
	char	*eof;
	int		fd;
	t_list	*temp;

	temp = shell->arg;

	eof = index_data(shell->arg, shell->heredoc + 2);
	fd = open("a.txt", O_WRONLY | O_CREAT | O_TRUNC | 0777);
	if (fd < 0)
		write(2, "Error\n", 6);
	else
	{
		while (1)
		{
			str = readline("heredoc> ");
			if (str == eof)
				break;
			ft_putstr_fd(str, fd);
			ft_putstr_fd("\n", fd);
			temp = temp->next;
		}
	}
	close(fd);
}

void	run_cmd_heredoc()
{
	int	pid;
	int	fd;

	fd = open("a.txt", O_RDWR | 0777);
	pid = fork();
	while (pid > 0)
	{
		dup2(fd, 0);
		close(fd);
		executor();
		exit(0);
	}
	wait(NULL);
	waitpid(pid, NULL, 0);
	close(fd);
}
