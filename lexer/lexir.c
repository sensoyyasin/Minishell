/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:56:41 by mtemel            #+#    #+#             */
/*   Updated: 2023/01/11 11:43:18 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	token_compare2(int *i)
{
	if (g_shell->line[*i] == '<' && g_shell->line[*i + 2] == '>')
	{
		g_shell->exit_status = 258;
		write(2, "syntax error near unexpected token\n", 35);
		return (-1);
	}
	else if (g_shell->line[*i] == '|' && g_shell->line[*i + 1] == '|')
	{
		g_shell->exit_status = 258;
		write(2, "syntax error near expected token '||'\n", 38);
		return (-1);
	}
	else
		return (1);
}

int	token_compare(void)
{
	int	i;

	i = 0;
	if (g_shell->line[i] == '>' || g_shell->line[i] == '<'
		|| g_shell->line[i] == '|')
	{
		if ((g_shell->line[i] == '>' && g_shell->line[i + 1] == '>')
			|| (g_shell->line[i] == '<' && g_shell->line[i + 1] == '<'))
			return (2);
		else if ((g_shell->line[i + 1] == '>' && g_shell->line[i + 2] == '>')
			|| (g_shell->line[i + 2] == '<' && g_shell->line[i + 1] == '<'))
		{
			write(2, "syntax error near unexpected token\n", 35);
			return (-1);
		}
		else
			return (token_compare2(&i));
	}
	return (0);
}

int	text_cmpr_stat(int *i)
{
	if (((g_shell->line[*i] != ' ' && g_shell->line[*i] != '\0')
			&& (g_shell->line[*i] != '>' && g_shell->line[*i] != '<'
				&& g_shell->line[*i] != '|')))
		return (1);
	else
		return (0);
}

int	text_cmpr(void)
{
	int (i) = 0;
	while (text_cmpr_stat(&i))
	{
		if (g_shell->line[i] == D_QUOTE)
		{
			i++;
			while (g_shell->line[i] != D_QUOTE && g_shell->line[i])
				i++;
			while (g_shell->line[i] != ' ' && g_shell->line[i] != '\0')
				i++;
			return (i + 1);
		}
		if (g_shell->line[i] == S_QUOTE)
		{
			i++;
			while (g_shell->line[i] != S_QUOTE && g_shell->line[i] != '\0')
				i++;
			while (g_shell->line[i] != ' ' && g_shell->line[i] != '\0')
				i++;
			return (i + 1);
		}
		i++;
	}
	return (i);
}

/* return command's next argument as char* */
char	*index_data(t_list *list, int index)
{
	int		i;
	t_list	*temp;

	i = 0;
	if (list == NULL)
		return (0);
	temp = list;
	while (i != index)
	{
		i++;
		temp = temp->next;
	}
	if (temp == NULL)
		return (0);
	return (temp->content);
}
