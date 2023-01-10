/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:12:14 by mtemel            #+#    #+#             */
/*   Updated: 2023/01/10 17:53:26 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fd_opener(int *i, int **fd)
{
	while ((*i) <= g_shell->pipe)
	{
		fd[*i] = malloc(sizeof(int) * 2);
		(*i)++;
	}
}

void	fd_checker(int *i, int ***fd)
{
	(*i) = 0;
	while ((*i) <= g_shell->pipe)
	{
		if (pipe((*fd)[*i]) < 0)
		{
			perror("");
			return ;
		}
		(*i)++;
	}
}

void	fork_work(int **fd)
{
	dup2((fd)[0][1], 1);
	multi_close(fd);
	check_cmnd2();
	exit(0);
}

void	big_pipe(int *i, int **fd)
{
	int		pid_1;
	t_list	*temp;

	temp = g_shell->arg;
	while (++(*i) < g_shell->pipe + 1)
	{
		while (!ft_strcmp(g_shell->arg->content, "|")
			&& g_shell->arg != NULL)
			g_shell->arg = g_shell->arg->next;
		if (ft_strcmp(g_shell->arg->content, "|"))
			g_shell->arg = g_shell->arg->next;
		pid_1 = fork();
		if (!pid_1)
		{
			dup2((fd)[(*i) - 1][0], 0);
			if ((*i) != (g_shell->pipe))
				dup2((fd)[*i][1], 1);
			multi_close(fd);
			check_cmnd2();
			exit(EXIT_SUCCESS);
		}
	}
	multi_close(fd);
	waitpid(pid_1, 0, 0);
	g_shell->arg = temp;
}
