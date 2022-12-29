/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_quote.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:56:02 by mtemel            #+#    #+#             */
/*   Updated: 2022/12/27 16:32:37 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_quote_dollar(char *content, int *i)
{
	while (content[*i] != 32 && content[*i] != '$' && content[*i] != '\0'
		&& content[*i] != D_QUOTE && content[*i] != S_QUOTE)
		(*i)++;
}

char	*dollar_filler(char **ret_dolar, int *j, char *temp)
{
	int (i) = 0;
	while ((*ret_dolar)[i])
	{
		temp[*j] = (*ret_dolar)[i];
		(*j)++;
		i++;
	}
	temp[*j] = '\0';
	return (temp);
}

char	*check_content_dquote(int *i, int *j, char **ret_dolar, char *temp)
{
	while (g_shell->my_content[*i])
	{
		if (g_shell->my_content[*i] == D_QUOTE)
			(*i)++;
		if (g_shell->my_content[*i] == '$'
			&& g_shell->my_content[(*i) + 1] != '"')
		{
			(*i)++;
			*ret_dolar = dollar_sign(g_shell->my_content, *i);
			check_quote_dollar(g_shell->my_content, i);
			temp = dollar_filler(ret_dolar, j, temp);
		}
		else if (g_shell->my_content[*i] != '"')
		{
			temp[*j] = g_shell->my_content[*i];
			(*i)++;
			(*j)++;
		}
		else
			(*i)++;
	}
	temp[*j] = '\0';
	return (temp);
}

void	d_quote(int index)
{
	char	*temp;
	char	*ret_dolar;

	int (j) = 0;
	int (i) = 0;
	ret_dolar = NULL;
	temp = malloc(500);
	g_shell->my_content = index_data(g_shell->arg, index);
	temp = check_content_dquote(&i, &j, &ret_dolar, temp);
	list_f_data(g_shell->arg, index)->content = ft_strdup(temp);
	free_str(&ret_dolar);
	free(temp);
}

char	*dollar_sign(char *str, int j)
{
	char	*tmp2;
	char	*a;

	int (i) = 0;
	tmp2 = malloc(size_finder(str, j) + 1);
	while (str[j] != '\0' && str[j] != 32 && str[j] != D_QUOTE
		&& str[j] != '$' && str[j] != S_QUOTE)
	{
		if (str[j] == '?')
			return (ft_itoa(g_shell->exit_status));
		tmp2[i] = str[j];
		i++;
		j++;
	}
	tmp2[i] = '\0';
	g_shell->temp = ft_strdup(tmp2);
	free(tmp2);
	a = check_env();
	if (a)
		return (a);
	return ("");
}
