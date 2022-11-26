/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:36:48 by ysensoy           #+#    #+#             */
/*   Updated: 2022/11/21 10:36:49 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(void)
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
		printf("%s\n",temp->content);
		temp = temp->next;
	}
}
