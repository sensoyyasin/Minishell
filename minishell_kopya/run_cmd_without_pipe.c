/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd_without_pipe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:41:01 by mtemel            #+#    #+#             */
/*   Updated: 2022/12/21 16:41:03 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*to_lower(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

void	run_cmd_without_pipe(t_list *list)
{
	char	*content;

	content = to_lower(list->content);
	if (ft_strcmp(content, "cd"))
		ft_cd(list);
	else if (ft_strcmp(content, "export"))
		ft_export(list);
	else if (ft_strcmp(content, "unset"))
		ft_unset(list);
	else if (ft_strcmp(content, "echo"))
		ft_echo(list);
	else if (ft_strcmp(content, "pwd"))
		ft_pwd();
	else if (ft_strcmp(content, "env"))
		ft_env();
	else if (ft_strcmp(content, "exit"))
		exit(0);
	else
		other_commands(list_changed(list));
}
