/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yonlendirici.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:39:30 by ysensoy           #+#    #+#             */
/*   Updated: 2022/11/21 11:03:52 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check(t_shell *shell)
{
	int i;

	i = 0;
	to_lower(shell->str[i]);
	if (ft_strncmp(shell->str[i], "echo", 4) || ft_strncmp(shell->str[i], "echo -n", 7))
	{
		i++;
		ft_echo(shell, i);
		return(1);
	}
	else if (ft_strcmp(shell->str[i], "export"))
		ft_export(shell);
	else if (ft_strcmp(shell->str[i], "env"))
		ft_env();
	else if (ft_strcmp(shell->str[i], "unset"))
		ft_unset(shell);
	else if (ft_strcmp(shell->str[i], "exit"))
		ft_exit(1);
	else if ((ft_strcmp(shell->str[i], "pwd") && !shell->str[i + 1]) || ft_strcmp(shell->str[i], "PWD"))
	{
		ft_pwd();
		return(1);
	}
	else if (ft_strcmp(shell->str[i], "cd"))
	{
		ft_cd(shell);
		return(1);
	}
	else if (other_cmnds(shell->str))
		return(1);
	return(0);
}

int check2(t_shell *shell, int i)
{
	char **temp;

	temp = ft_split(shell->str_pipe[i], ' ');
	other_cmnds(temp);
	return(1);
}
