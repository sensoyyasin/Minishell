/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:45:54 by ysensoy           #+#    #+#             */
/*   Updated: 2022/10/21 15:35:09 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(t_list *shell, int i)
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
