#include "minishell.h"

void	multi_close(int **fd)
{
	int i;

	i = 0;
	while (i <= shell->pipe)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
	free(fd);
}

void	check_cmnd2()
{
	while (!ft_strcmp(shell->arg->content, "|") && shell->arg != NULL)
	{
		ft_lstadd_back(&shell->pipe_arg, ft_lstnew(shell->arg->content));
		shell->arg = shell->arg->next;
		if (shell->arg == NULL)
			break;
	}
	run_cmd_without_pipe(shell->pipe_arg);
}

void	shell_pipe_dup2()
{
	int		i = 0;
	int		**fd;
	pid_t	pid;

	fd = malloc(sizeof(int *) * (shell->pipe + 1));
	while (i <= shell->pipe)
	{
		fd[i] = malloc(sizeof(int) * 2);
		i++;
	}
	i = 0;
	while (i <= shell->pipe)
	{
		if (pipe(fd[i]) < 0)
		{
			perror("");
			return;
		}
		i++;
	}
	i = 0;
	pid = fork();
	if (pid == 0)//child
	{
		dup2(fd[0][1], 1); // yeni fork olustu.
		//printf("A\n"); -> bu artik child processte olusur. mainde yazdiramam
		multi_close(fd);
		check_cmnd2();
		exit(0);
	}
	else
	{
		i++;
		while (i < shell->pipe + 1)
		{
			while (!ft_strcmp(shell->arg->content, "|") && shell->arg != NULL)
				shell->arg = shell->arg->next;
			if (ft_strcmp(shell->arg->content, "|"))
				shell->arg = shell->arg->next;
			if (!fork())
			{
				dup2(fd[i - 1][0], 0);
				if (i != shell->pipe)
					dup2(fd[i][1], 1);
				multi_close(fd);
				check_cmnd2();
				exit(0);
			}
			i++;
		}
		///parent
		waitpid(pid, NULL, 0);
		multi_close(fd);
		wait(NULL);
	}
}
