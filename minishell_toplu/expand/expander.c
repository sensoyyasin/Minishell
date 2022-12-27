/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:43:11 by mtemel            #+#    #+#             */
/*   Updated: 2022/12/27 16:32:37 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	expand(int index)
{
	char	*content;
	char	*temp;
	char	*a;

	int (i) = 0;
	int (j) = 0;
	temp = malloc(1000);
	content = index_data(g_shell->arg, index);
	while (content[i])
	{
		if (content[i] == '$' && content[i + 1] != '\0')
		{
			a = dollar_sign(content, ++i);
			temp = ft_strjoin(temp, a);
			while (content[i] != 32 && content[i] != '$' && content[i] != '\0')
				i++;
			while (j < ft_strlen(temp))
				j++;
		}
		temp[j++] = content[i++];
	}
	temp[j] = '\0';
	list_f_data(g_shell->arg, index)->content = ft_strdup(temp);
	free(temp);
	free_str(&a);
}

void	expander(void)
{
	t_list	*iter;
	char	*content;
	int		quote_varmi;
	int		index;

	index = 0;
	iter = g_shell->arg;
	while (iter != NULL)
	{
		content = iter->content;
		quote_varmi = quote_check(content);
		if (quote_varmi == D_QUOTE)
			d_quote(index);
		else if (quote_varmi == S_QUOTE)
			s_quote(index);
		else
			expand(index);
		iter = iter->next;
		index++;
		free(content);
	}
}

void	s_quote(int index)
{
	char	*content;
	char	*temp;
	int		i;
	int		j;

	temp = malloc(500);
	i = 0;
	j = 0;
	content = index_data(g_shell->arg, index);
	if (content[i] == S_QUOTE)
	{
		i++;
		while (content[i] && content[i] != S_QUOTE)
		{
			temp[j] = content[i];
			i++;
			j++;
		}
		while (content[++i])
			temp[j++] = content[i];
		temp[j] = '\0';
	}
	list_f_data(g_shell->arg, index)->content = ft_strdup(temp);
	free(temp);
}

t_list	*list_f_data(t_list *root, int index)
{
	t_list	*list;
	int		i;

	if (!root)
		return (NULL);
	list = root;
	i = 0;
	while (i != index)
	{
		i++;
		list = list->next;
	}
	return (list);
}

int	quote_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == D_QUOTE)
			return (D_QUOTE);
		else if (str[i] == S_QUOTE)
			return (S_QUOTE);
		i++;
	}
	return (0);
}
