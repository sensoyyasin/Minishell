/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:15:18 by ysensoy           #+#    #+#             */
/*   Updated: 2022/11/23 16:18:27 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_size()
{
	int i = 0;
	int j = 0;
	int k = 0;
	int res = 0;
	char *temp = NULL;

	temp = malloc(10000);
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
						get[k] = shell->str[i][j];
						j++;
						k++;
					}
					get[k] = '\0';
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

char	*pars_fquote()
{
	int	i = 0;
	int	j;
	char *tmp = NULL;
	int t_i = 0;

	tmp = malloc(find_size() + 1);
	while (shell->str[i])
	{
		j = 0;
		while(shell->str[i][j])
		{
			if (shell->str[i][j] == 34)
			{
				j++;
				tmp = d_quote(i, j, t_i, tmp);
			}
			else if (shell->str[i][j] == 39)
			{
				j++;
				tmp = s_quote(i, j, t_i, tmp);
			}
			j++;
			shell->len++;
		}
		ft_memset(tmp, '\0', ft_strlen(tmp));
		i++;
	}
	free(tmp);
	return(final_line());
}

char	*final_line()
{
	char	*f_line;
	int		i = 0;
	int		j = 0;
	int		k = 0;
	f_line = malloc(sizeof(char) * (shell->len + 1));
	while (shell->str[i])
	{
		while (shell->str[i][j])
		{
			f_line[k] = shell->str[i][j];
			k++;
			j++;
		}
		f_line[k] = 32;
		k++;
		j = 0;
		i++;
	}
	f_line[k] = '\0';
	return(f_line);
}

// int     size_squote(t_shell *shell)
// {
//     int i = 0;
//     int j = 0;
//     int k = 0;
//     int res = 0;
//     char *temp;

// 	temp = malloc(500);
// 	if (shell->str[i] && shell->str[i][j] == 39)
// 	{
// 		j++;
// 		while (shell->str[i][j])
// 		{
// 			temp[k] = shell->str[i][j];
// 			j++;
// 			k++;
// 		}
// 		res += ft_strlen(temp);
// 		i++;
// 		free(temp);
// 	}
// 	return(res);
// }

// int		d_quote(t_shell *shell)
// {
// 	int	i = 0;
// 	int	j = 0;
// 	int	k = 0;
// 	char	*temp;

// 	temp = malloc(500);
// 	if (shell->str[i] && shell->str[i][j] == 34)
// 	{
// 		j++;
// 		if (shell->str[i][j] == '$')
// 		{
// 			j++;
// 			while (shell->str[i][j] >= 65 && shell->str[i][j] <= 90)
// 			{
// 				temp[k] = shell->str[i][j];
// 				j++;
// 				k++;
// 			}
// 			temp[k] = '\0';
// 		}
// 		if (getenv(temp) != NULL)
// 			res += ft_strlen(temp);
// 		free(temp);
// 	}
// }

void	quote_sayici(t_shell *shell)
{
	int i;
	int j;

	i = 0;
	shell->quote = 0;
	while (shell->str[i])
	{
		j = 0;
		while (shell->str[i][j])
		{
			if (shell->str[i][j] == '<' && shell->str[i][j + 1] == '<')
				shell->quote++;
			j++;
		}
		i++;
	}
}
