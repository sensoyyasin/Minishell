/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_sleft.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:45:57 by mtemel            #+#    #+#             */
/*   Updated: 2022/12/27 16:32:37 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	single_left_redirection2(int *fd, char **str)
{
	signal(SIGINT, pro_fork);
	*str = index_data(g_shell->arg, single_left_redirect_list() + 1);
	*fd = open(*str, O_RDWR, 0777);
	if (*fd < 0)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	else
	{
		hdelete_node(&g_shell->arg, index_data(g_shell->arg,
				single_left_redirect_list()));
		dup2(*fd, 0);
		close(*fd);
		if (!check_token())
			executor();
		exit(0);
	}
}

void	single_left_redirection(void)
{
	int		a;
	int		fd;
	char	*str;

	g_shell->fpid = fork();
	if (g_shell->fpid == 0)
	{
		single_left_redirection2(&fd, &str);
	}
	waitpid(-1, &a, 0);
	if (a != 0)
		return ;
}

int	single_left_redirect_list(void)
{
	t_list	*iter;
	int		i;

	i = 0;
	iter = g_shell->arg;
	while (iter != NULL)
	{
		if (ft_strcmp(iter->content, "<"))
			return (i);
		i++;
		iter = iter->next;
	}
	return (0);
}
