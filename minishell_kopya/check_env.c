/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:03:12 by mtemel            #+#    #+#             */
/*   Updated: 2022/12/23 18:17:01 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_str_eq_dup(char *s1)
{
	char	*s2;
	int		len;
	int		i;

	len = 0;
	while (s1[len] != '=' && s1[len] != '\0')
		len++;
	s2 = malloc(sizeof(char) * len + 1);
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '=' && s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

/* is there a variable
check if there is an equal mark */
char	*check_env(void)
{
	t_list	*t_temp;
	char	*temp2;
	int		i;

	if (!g_shell->asd)
		ft_fill();
	t_temp = g_shell->asd;
	while (t_temp != NULL)
	{
		temp2 = ft_str_eq_dup(t_temp->content);
		i = ft_strlen(temp2);
		if (ft_strcmp(temp2, g_shell->temp) && t_temp->content[i] != '\0')
		{
			free(temp2);
			free(g_shell->temp);
			return (ret_env(i + 1, t_temp->content));
		}
		else if (t_temp->content[i] == '\0')
			return (NULL);
		free(temp2);
		t_temp = t_temp->next;
	}
	return (NULL);
}

/* return the string after the equal sign */
char	*ret_env(int i, char *str)
{
	char	*ret;
	int		j;

	j = i;
	while (str[j])
	{
		j++;
	}
	ret = malloc(sizeof(char *) * (j + 1));
	j = 0;
	while (str[i])
		ret[j++] = str[i++];
	ret[j] = '\0';
	return (ret);
}
