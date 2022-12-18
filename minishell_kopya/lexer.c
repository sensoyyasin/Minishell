/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:48:49 by mtemel            #+#    #+#             */
/*   Updated: 2022/12/18 15:50:32 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmnd_length(void)
{
	int	i;

	i = 0;
	if (shell->line[0] == '|')
	{
		write(2, "syntax error near unexpected token `|'\n", 39);
		return (-1);
	}
	while (shell->line[i] > 32 && shell->line[i] != '|' && shell->line[i] != '>'
		&& shell->line[i] != '<' && shell->line[i])
		i++;
	return (i);
}

void	lexir(int count)
{
	int		i;
	char	*temp;

	i = 0;
	temp = malloc(sizeof(t_list));
	while (count > 0 && *(shell->line))
	{
		temp[i] = *(shell->line);
		shell->line++;
		i++;
		count--;
	}
	temp[i] = '\0';
	ft_lstadd_back(&shell->arg, ft_lstnew(temp));
	free(temp);
}

void	space_skip(void)
{
	int	i;

	i = 0;
	while (((shell->line[i] >= 9 && shell->line[i] <= 13)
			|| shell->line[i] == 32) && shell->line[i + 1] != '\0')
		shell->line++;
	if (((shell->line[i] >= 9 && shell->line[i] <= 13)
			|| shell->line[i] == 32) && shell->line[i + 1] == '\0')
	{
		*shell->line = '\0';
		return ;
	}
}

int	lexer(void)
{
	int	count;

	while (*shell->line)
	{
		space_skip();
		if (shell->arg == NULL)
		{
			count = cmnd_length();
			if (count <= 0)
				return (0);
			else if (count > 0)
				lexir(count);
		}
		count = token_compare();
		if (count > 0)
			lexir(count);
		else if (count == -1)
			return (0);
		count = text_cmpr();
		if (count > 0)
			lexir(count);
	}
	return (1);
}
