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
			i++;
		iter = iter->next;
	}
	return(i);
}

void	heredoc_f()
{
	char	*str;
	char	*eof;
	int		fd;

	eof = index_data(shell->arg, heredoc_list() + 2);
	fd = open("a.txt", O_WRONLY | O_CREAT | O_TRUNC);
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

// void    run_heredoc(int i)
// {
//     int fd;
//     int pid;
//     char *temp;
//     char *path;
//     pid = fork();
//     if (pid == 0)
//     {
//         fd = open(".heredoc", O_RDWR, 0777);
//         if (fd < 0)
//             return ;
//         dup2(fd, 0);
//         close(fd);
//         // temp = ft_strdup(list_data(shell->arg, i));
//         // // char *catf[] = {temp, NULL};
//         // // path = ft_strjoin("/bin/", list_data(shell->arg, i));
//         // // execve(path, catf, NULL);
//         executor();
//         exit(0);
//     }
//     wait(NULL);
//     waitpid(pid, NULL, -1);
// }
