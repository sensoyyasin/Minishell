/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:38:08 by ysensoy           #+#    #+#             */
/*   Updated: 2022/11/21 10:38:08 by ysensoy          ###   ########.fr       */
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