/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_pipe_dup2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:38:06 by ysensoy           #+#    #+#             */
/*   Updated: 2022/11/21 10:38:06 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	multi_close(int **fd)
{
	int i;

	i = 0;
	while (fd[i])
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
}

void	shell_pipe_dup2(t_shell *shell)
{
	int i = 0;
	int **fd;

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
	//Child process has been created
	if (fork() == 0)
	{
		dup2(fd[0][1], STDOUT_FILENO);
		multi_close(fd);
		check2(shell, i);
		exit(EXIT_SUCCESS);
	}
	i++;
	while (i < shell->pipe + 1)
	{
		if (fork() == 0)
		{
			dup2(fd[i - 1][0], STDIN_FILENO);
			if (i != shell->pipe)
				dup2(fd[i][1], STDOUT_FILENO);
			multi_close(fd);
			check2(shell,i);
			exit(EXIT_SUCCESS);
		}
		i++;
	}
	multi_close(fd);
	wait(NULL);
}