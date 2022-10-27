#include "minishell.h"

// void	multi_close(int **fd)
// {
// 	int i;

// 	i = 0;
// 	while (fd[i])
// 	{
// 		close(fd[i][0]);
// 		close(fd[i][1]);
// 		i++;
// 	}
// }

void	shell_pipe_dup2(t_list *shell)
{
	int i = 0;
	int **fd;
	int pid;

	fd = malloc(sizeof(int *) * shell->pipe	+ 1);
	while (i < shell->pipe)
	{
		fd[i] = malloc(sizeof(int) * 2);
		i++;
	}
	i = 0;
	while (i < shell->pipe)
	{
		if (pipe(fd[i]) == -1)
		{
			perror("");
			return;
		}
		i++;
	}
	i = 0;
	while (i < shell->pipe + 1)
	{
		pid = fork(); //Child process oluştu
		if (pid == 0)
		{
			if (i == 0)
			{
				dup2(fd[0][1], STDOUT_FILENO);
				close(fd[0][0]);
				close(fd[0][1]);
				check2(shell, i);
				exit(1);
			}
			else
			{
				dup2(fd[0][0],STDIN_FILENO);
				close(fd[0][0]);
				close(fd[0][1]);
				check2(shell, i);
				exit(1);
			}
			i++;
		}
		close(fd[0][0]);
		close(fd[0][1]);
		wait(NULL);
		i++;
	}
}

