/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:14:43 by ysensoy           #+#    #+#             */
/*   Updated: 2022/10/27 13:38:37 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_pwd(void)
{
	char str[256];

	if (getcwd(str, sizeof(str)) != NULL)
	{
		printf("%s\n",str);
		return (1);
	}
	else
		perror("");
	return(0);
}
