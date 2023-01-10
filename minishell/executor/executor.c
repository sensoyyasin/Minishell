/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:41:32 by mtemel            #+#    #+#             */
/*   Updated: 2023/01/10 16:59:49 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	pipe_stat(void)
{
	t_list	*iter;

	iter = g_shell->arg;
	while (iter != NULL)
	{
		if (ft_strcmp(iter->content, "|"))
		{
			if (iter->next == NULL)
			{
				printf("This was just a pipe.\n");
				return (-1);
			}
			return (1);
		}
		iter = iter->next;
	}
	return (0);
}

void	executor(void)
{
	int	stat;

	stat = pipe_stat();
	if (stat)
		run_cmd_with_pipe();
	else if (!stat)
		run_cmd_without_pipe(g_shell->arg);
	else
		return ;
}
