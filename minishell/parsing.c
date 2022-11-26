// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   parsing.c                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/11/23 16:15:18 by ysensoy           #+#    #+#             */
// /*   Updated: 2022/11/26 17:19:00 by ysensoy          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

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
	char *temp = NULL;

	temp = malloc(find_size(shell) + 1);
	while (shell->str[i])
	{
		j = 0;
		while(shell->str[i][j])
		{
			if (shell->str[i][j] == 34)
			{
				j++;
				temp = d_quote(shell, i, j);
				while (shell->str[i][j] != 34 && shell->str[i][j] == '\0')
					j++;
			}
			if (shell->str[i][j] == 39)
			{
				j++;
				temp = s_quote(shell, i, j);
				while (shell->str[i][j] != 39)
					j++;
			}
			j++;
			shell->len++;
		}
		ft_memset(temp, '\0', ft_strlen(temp));
		i++;
	}
	free(temp);
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
		j = 0;
		while (shell->str[i][j])
		{
			str[k] = shell->str[i][j];
			k++;
			j++;
		}
		str[k] = 32;
		k++;
		i++;
	}
	str[k] = '\0';
	return(str);
}

char	*s_quote(t_shell *shell, int i, int j)
{
	int		k = 0;
	char	*temp;

	temp = malloc(500);
	while (shell->str[i][j] != 39)
	{
		temp[k] = shell->str[i][j];
		j++;
		k++;
	}
	shell->len += ft_strlen(temp);
	ft_strlcpy(shell->str[i], temp, (ft_strlen(temp) + 1));
	return(temp);
}

char	*dollar_sign(t_shell *shell, char *str, int j)
{

	int i = 0;
	char	*temp2;

	temp2 = malloc(500);
	while (str[j] != '\0' && str[j] != 32 && str[j] != 34 && str[j] != '$')
	{
		temp2[i] = str[j];
		i++;
		j++;
	}
	temp2[i] = '\0';
	shell->temp = temp2;
	if (check_env())
		return (check_env());
	return ("");
}

char	*d_quote(t_shell *shell, int i, int j)
{
	int k = 0;
	char *temp;

	temp = malloc(500);
	while (shell->str[i][j] != 34 && shell->str[i][j] != '\0')
	{
		if (shell->str[i][j] == '$')
		{
			j++;
			temp = ft_strjoin(temp, dollar_sign(shell, shell->str[i], j));
			while (shell->str[i][j] != 32 && shell->str[i][j] != '\0' && shell->str[i][j] != 34 && shell->str[i][j] != '$')
				j++;
		}
		while (shell->str[i][j] != 34)
		{
			temp[k] = shell->str[i][j];
			j++;
			k++;
		}
		if (shell->str[i][j] == 39)
		{
			j++;
			k--;
			while (shell->str[i][j] != 39 && shell->str[i][j] != '\0')
			{
				temp[k] = shell->str[i][j];
				k++;
				j++;
			}
			k++;
			j++;
		}
		else
		{
			while (shell->str[i][j] != 34)
			{
				temp[k] = shell->str[i][j];
				k++;
				j++;
			}
		}
	}
	shell->len += ft_strlen(temp);
	ft_strlcpy(shell->str[i], temp, (ft_strlen(temp) + 1));
	return (temp);
}

char *ret_env(int i, char *str)
{
	char *ret;
	int j;

	j = 0;
	ret = malloc(500);
	while (str[i])
	{
		ret[j] = str[i];
		i++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

char *check_env(void)
{
	t_list	*l_tmp;
	char	*temp;
	char	*temp2;
	int		i = 0;

	if (!(shell->x))
		fill(shell);
	l_tmp = shell->x;
	while (l_tmp != NULL)
	{
		temp = (char *)l_tmp->content;
		//printf("a\n");
		while (temp[i] != '=')
			i++;
		// printf("b\n"); -> buraya gelmiyor.
		temp2 = malloc(sizeof(char) * i);
		i = 0;
		while (temp[i] != '=')
		{
			temp2[i] = temp[i];
			i++;
		}
		temp2[i] = '\0';
		if (ft_strcmp(temp2, shell->temp))
			return (ret_env(i + 1, temp));
		l_tmp = l_tmp->next;
		i = 0;
	}
	return (NULL);
}
