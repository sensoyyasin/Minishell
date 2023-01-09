/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:12:14 by mtemel            #+#    #+#             */
/*   Updated: 2023/01/09 16:04:53 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	multi_close(int **fd)
{
	int	i;

	i = 0;
	while (i <= g_shell->pipe)
	{
		if (close(fd[i][0]) < 0)
			perror("hata1");
		if (close(fd[i][1]) < 0)
			perror("hata2");
		free(fd[i]);
		i++;
	}
	free(fd);
}

void	check_cmnd2(void)
{
	while (!ft_strcmp(g_shell->arg->content, "|") && g_shell->arg != NULL)
	{
		g_shell->exit_status = 0;
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
	t_list	*tmp;

	tmp = g_shell->arg;
	int (i) = 0;
	fd = (int **)malloc(sizeof(int *) * (g_shell->pipe + 1));
	fd_opener(&i, fd);
	fd_checker(&i, &fd);
	i = 0;
	pid = fork();
	if (pid == 0)
		fork_work(fd);
	else
		big_pipe(&i, fd, &pid);
	//waitpid(pid, NULL, 0);
	//g_shell->arg = tmp;
}
