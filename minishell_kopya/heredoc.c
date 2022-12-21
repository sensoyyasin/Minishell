/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:28:47 by mtemel            #+#    #+#             */
/*   Updated: 2022/12/21 16:50:49 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	heredoc_cnt(void)
{
	t_list	*iter;

	iter = g_shell->arg;
	g_shell->heredoc = 0;
	while (iter != NULL)
	{
		if (ft_strcmp(iter->content, "<<") && !ft_strcmp(iter->content, ">>"))
			g_shell->heredoc++;
		iter = iter->next;
	}
	return (g_shell->heredoc);
}

int	heredoc_list(void)
{
	t_list	*iter;
	int		i;

	i = 0;
	iter = g_shell->arg;
	while (iter != NULL)
	{
		if (ft_strcmp(iter->content, "<<"))
			return (i);
		i++;
		iter = iter->next;
	}
	return (0);
}

void	heredoc_functions(void)
{
	int	a;

	g_shell->fpid = fork();
	if (g_shell->fpid == 0)
	{
		signal(SIGINT, pro_fork);
		heredoc_f();
		hdelete_node(&g_shell->arg, index_data(g_shell->arg,
				heredoc_list() + 1));
		hdelete_node(&g_shell->arg, index_data(g_shell->arg, heredoc_list()));
		run_cmd_heredoc();
		exit(0);
	}
	waitpid(-1, &a, 0);
	if (a != 0)
		return ;
}

/* start readline till eof occured */
void	heredoc_f(void)
{
	char	*str;
	char	*eof;
	int		fd;

	if (g_shell->fpid == 0)
	{
		eof = index_data(g_shell->arg, heredoc_list() + 1);
		fd = open(".heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd < 0)
			write(2, "Error\n", 6);
		else
		{
			heredoc_f2(&str, &eof, &fd);
		}
		close(fd);
	}
	return ;
}

/* if there is a child process
(fpid == 0), execute the command */
void	run_cmd_heredoc(void)
{
	int	fd;

	if (g_shell->fpid == 0)
	{
		fd = open(".heredoc", O_RDWR);
		if (fd < 0)
			write(2, "Error\n", 6);
		dup2(fd, 0);
		close(fd);
		if (!check_token())
			executor();
		exit(0);
	}
}
