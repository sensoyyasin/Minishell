/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:35:38 by ysensoy           #+#    #+#             */
/*   Updated: 2022/11/25 13:58:57 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_cd(t_shell *shell)
{
	char *str = NULL;
	int i;

	i = 0;
	if (shell->str[i + 1] != NULL)
	{
		str = ft_strjoin(getcwd(str, sizeof(str)),"/");
		i++;
		if (!shell->str[i])
			return(0);
		str = ft_strjoin(str, shell->str[i]);
		chdir(str);
		return(1);
	}
	else
	{
		str = getenv("HOME");
		chdir(str);
		return(1);
	}
	return(0);
}
