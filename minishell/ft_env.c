/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinsensoy <yasinsensoy@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:36:48 by ysensoy           #+#    #+#             */
/*   Updated: 2022/11/23 21:04:02 by yasinsensoy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_shell *shell)
{
	t_list	*temp;

	if (shell->sayi == 42)
	{
		fill(shell);
		shell->sayi++;
	}
	temp = shell->x;
	temp = temp->next;
	while (temp != NULL)
	{
		printf("%s\n",(char *)temp->content);
		temp = temp->next;
	}
}