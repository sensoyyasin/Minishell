/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:38:50 by ysensoy           #+#    #+#             */
/*   Updated: 2022/11/23 13:21:55 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(t_shell *shell, int i)
{
	int j = 0;
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
		if (shell->str[i][j] == 34)
			d_quote(shell->str[i]);
		else if (shell->str[i][j] == 39)
			s_quote(shell->str[i]);
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