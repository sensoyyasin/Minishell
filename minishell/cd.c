/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:50:02 by ysensoy           #+#    #+#             */
/*   Updated: 2022/10/23 14:28:57 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_cd(t_list *shell)
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
