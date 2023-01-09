/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd_without_pipe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:41:01 by mtemel            #+#    #+#             */
/*   Updated: 2023/01/09 17:06:30 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
		ft_exit(list);
	else
		other_commands(list_changed(list));
}

void	ft_exit(t_list *list)
{
	int		i;

	i = 0;
	if (index_data(list, 0) && !index_data(list, 1))
		exit(EXIT_SUCCESS);
	if ((index_data(list, 1)) && !index_data(list, 2))
	{
		g_shell->iter = index_data(list, 1);
		printf("exit\n");
		exit(EXIT_SUCCESS);
	}
	else
		printf("bash: %s: too many arguments\n", list->content);
	return ;
}
