/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:11:22 by mtemel            #+#    #+#             */
/*   Updated: 2023/01/09 16:04:17 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pipe_counter(void)
{
	t_list	*iter;

	iter = g_shell->arg;
	g_shell->pipe = 0;
	while (iter != NULL)
	{
		if (ft_strcmp(iter->content, "|"))
			g_shell->pipe++;
		iter = iter->next;
	}
}

void	run_cmd_with_pipe(void)
{
	ft_pipe_counter();
	g_shell_pipe_dup2();
	g_shell->pipe = 0;
}
