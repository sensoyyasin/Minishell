/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yonlendirici.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:45:44 by ysensoy           #+#    #+#             */
/*   Updated: 2022/10/21 19:41:53 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check(t_list *shell)
{
	int i;

	i = 0;
	if (ft_strncmp(shell->str[i], "echo", 4) || ft_strncmp(shell->str[i], "echo -n", 7))
	{
		i++;
		//if (ft_strcmp(shell->str[i], '"'))
			//dquotecontrol(shell->str[i]);
		ft_echo(shell, i);
		return(1);
	}
	else if (ft_strcmp(shell->str[i], "exit"))
	{
		ft_exit(1);
		return(1);
	}
	else if ((ft_strcmp(shell->str[i], "pwd") && !shell->str[i + 1]) || ft_strcmp(shell->str[i], "PWD"))
	{
		ft_pwd(shell->str[i]);
		return(1);
	}
	else if (other_cmnds(shell->str[i]))
		return(1);
	return(0);
}
