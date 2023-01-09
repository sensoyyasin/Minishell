/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinsensoy <yasinsensoy@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:12:41 by mtemel            #+#    #+#             */
/*   Updated: 2023/01/08 14:44:31 by yasinsensoy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	checker_tkn(char *str)
{
	if (ft_strcmp(str, ">>"))
	{
		double_right_redirection();
		return (1);
	}
	else if (ft_strcmp(str, ">"))
	{
		single_right_redirection();
		return (1);
	}
	else if (ft_strcmp(str, "<"))
	{
		single_left_redirection();
		return (1);
	}
	else if (ft_strcmp(str, "<<"))
	{
		heredoc_functions();
		return (1);
	}
	return (0);
}

int	check_token(void)
{
	t_list	*iter;

	iter = g_shell->arg;
	while (iter != NULL)
	{
		if (checker_tkn(iter->content))
			return (1);
		iter = iter->next;
	}
	return (0);
}
