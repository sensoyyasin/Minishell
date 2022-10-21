/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:50:02 by ysensoy           #+#    #+#             */
/*   Updated: 2022/10/15 14:44:21 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_cd(t_list *shell, int i)
{
	char *str;

	if (shell->str[i + 1] != NULL)
	{
		str = ft_strjoin(getenv("PWD"),"/");
		i++;
		if (!shell->str[i])
			return(0);
		str = ft_strjoin(str, shell->str[i]);
		chdir(str);
		return(1);
	}
	return(0);
}
