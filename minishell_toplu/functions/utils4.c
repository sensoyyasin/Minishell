/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:41:52 by mtemel            #+#    #+#             */
/*   Updated: 2022/12/28 16:56:49 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	size_finder(char *str, int j)
{
	while (str[j] != '\0' && str[j] != 32 && str[j] != D_QUOTE && str[j] != '$')
		j++;
	return (j);
}

void	heredoc_f2(char **str, char **eof, int *fd)
{
	while (1)
	{
		*str = readline("> ");
		if (!(*str))
			break ;
		if (ft_strcmp(*str, *eof))
			break ;
		ft_putstr_fd(*str, *fd);
		ft_putstr_fd("\n", *fd);
	}
	free(*str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/* return 1 if strings equal
return 0 if there is any difference */
int	ft_strcmp(char *str, char *str2)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(str2);
	if (!str)
		return (0);
	while (len)
	{
		if (str[i] == str2[i])
			i++;
		else
			return (0);
		len--;
	}
	if (str[i] != '\0')
		return (0);
	return (1);
}

void	free_str(char **ret_dolar)
{
	if (*ret_dolar && **ret_dolar >= 32)
	{
		free(*ret_dolar);
		*ret_dolar = NULL;
	}
}
void	free_p_list(void)
{
	printf("lst address: %p\n", &g_shell->pipe_arg);
	while (g_shell->pipe_arg != NULL)
	{
		printf("lst address: %p\n", &g_shell->pipe_arg);
		free(g_shell->pipe_arg->content);
		free(g_shell->pipe_arg);
		g_shell->pipe_arg = g_shell->pipe_arg->next;
	}
}
