/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinsensoy <yasinsensoy@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:38:50 by ysensoy           #+#    #+#             */
/*   Updated: 2022/11/23 20:52:37 by yasinsensoy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(t_shell *shell, int i)
{
	if (ft_strcmp(shell->str[i], "-n") == 1)
	{
		i++;
		while (shell->str[i])
		{
			printf("%s",shell->str[i]);
			if (shell->str[i + 1])
				printf(" ");
			i++;
		}
	}
	else if (shell->str[i])
	{
		while (shell->str[i])
		{
			printf("%s",shell->str[i]);
			if (shell->str[i + 1])
				printf(" ");
			i++;
		}
		printf("\n");
	}
	else
		printf("\n");
	return(1);
}