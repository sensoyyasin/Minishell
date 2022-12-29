/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:12:14 by mtemel            #+#    #+#             */
/*   Updated: 2022/12/28 16:08:20 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	multi_close(int **fd)
{
	int	i;

	i = 0;
	while (i <= g_shell->pipe)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		free(fd[i]);
		i++;
	}
	free(fd);
}

void	check_cmnd2(void)
{
	while (!ft_strcmp(g_shell->arg->content, "|") && g_shell->arg != NULL)
	{
		ft_lstadd_back(&g_shell->pipe_arg, ft_lstnew(g_shell->arg->content));
		g_shell->arg = g_shell->arg->next;
		if (g_shell->arg == NULL)
			break ;
	}
	run_cmd_without_pipe(g_shell->pipe_arg);
}

void	g_shell_pipe_dup2(void)
{
	int		**fd;
	pid_t	pid;

	int (i) = 0;
	fd = (int **)malloc(sizeof(int *) * (g_shell->pipe + 1));
	while (i <= g_shell->pipe)
	{
		fd[i] = malloc(sizeof(int) * 2);
		i++;
	}
	i = 0;
	while (i <= g_shell->pipe)
	{
		if (pipe(fd[i]) < 0)
		{
			perror("");
			return ;
		}
		i++;
	}
	i = 0;
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[0][1], 1);
		multi_close(fd);
		check_cmnd2();
		exit(0);
	}
	else
	{
		i++;
		while (i < g_shell->pipe + 1)
		{
			while (!ft_strcmp(g_shell->arg->content, "|")
				&& g_shell->arg != NULL)
			{
				g_shell->arg = g_shell->arg->next;
			}
			if (ft_strcmp(g_shell->arg->content, "|"))
			{
				g_shell->arg = g_shell->arg->next;
			}
			if (!fork())
			{
				dup2(fd[i - 1][0], 0);
				if (i != g_shell->pipe)
					dup2(fd[i][1], 1);
				multi_close(fd);
				check_cmnd2();
				exit(0);
			}
			i++;
		}
		waitpid(pid, NULL, 0);
		multi_close(fd);
		wait(NULL);
	}
}
