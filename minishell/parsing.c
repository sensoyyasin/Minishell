/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:15:18 by ysensoy           #+#    #+#             */
/*   Updated: 2022/11/25 17:21:11 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_size(t_shell *shell)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int res = 0;
	char *temp = NULL;

	temp = malloc(5000);
	while (shell->str[i])
	{
		j = 0;
		if (shell->str[i][j] == 34 || shell->str[i][j] == 39)
		{
			j++;
			while (shell->str[i][j] != 34 && shell->str[i][j] != 39 && shell->str[i][j])
			{
				if (shell->str[i][j] == '$')
				{
					j++;
					while (shell->str[i][j] != 34 && shell->str[i][j] != 32)
					{
						temp[k] = shell->str[i][j];
						j++;
						k++;
					}
					temp[k] = '\0';
					k = 0;
					if (getenv(temp) != NULL)
						res += ft_strlen(getenv(temp));
				}
				res++;
				j++;
			}
		}
		i++;
	}
	free(temp);
	return(res);
}

char	*expand_quote(t_shell *shell)
{
	int	i = 0;
	int	j;
	char *tmp = NULL;

	tmp = malloc(find_size(shell) + 1);
	while (shell->str[i])
	{
		j = 0;
		while(shell->str[i][j])
		{
			if (shell->str[i][j] == 34)
			{
				j++;
				tmp = d_quote(shell);
			}
			if (shell->str[i][j] == 39)
			{
				j++;
				tmp = s_quote(shell);
			}
			j++;
			shell->len++;
		}
		ft_memset(tmp, '\0', ft_strlen(tmp));
		i++;
	}
	free(tmp);
	return(final_line(shell));
}

char	*final_line(t_shell *shell)
{
	char	*str;
	int		i = 0;
	int		j = 0;
	int		k = 0;
	str = malloc(sizeof(char) * (shell->len + 1));
	while (shell->str[i])
	{
		while (shell->str[i][j])
		{
			str[k] = shell->str[i][j];
			k++;
			j++;
		}
		str[k] = 32;
		k++;
		j = 0;
		i++;
	}
	str[k] = '\0';
	return(str);
}

char	*d_quote(t_shell *shell)
{
	int 	i = 0;
	int 	j = 0;
	int		k = 0;
	char	*temp;

	temp = malloc(500);
	if (shell->str[i] && shell->str[i][j] != 34)
	{
		while (shell->str[i][j])
		{
			temp[k] = shell->str[i][j];
			j++;
			k++;
		}
		temp[k] = '\0';
	}
	return(temp);
}

char	*s_quote(t_shell *shell)
{
	int		i = 0;
	int		j = 0;
	int		k = 0;
	char	*temp;

	temp = malloc(500);
	if (shell->str[i] && shell->str[i][j] != 39)
	{
		while (shell->str[i][j])
		{
			temp[k] = shell->str[i][j];
			j++;
			k++;
		}
		temp[k] = '\0';
	}
	return(temp);
}
