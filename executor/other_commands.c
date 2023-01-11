/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:07:52 by mtemel            #+#    #+#             */
/*   Updated: 2023/01/10 21:35:45 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**list_changed(t_list *list)
{
	t_list	*temp;
	char	**str;
	int		i;

	i = 0;
	temp = list;
	str = malloc(sizeof(char **) * ft_listsize(list) + 1);
	while (temp != NULL)
	{
		str[i] = ft_strdup(temp->content);
		temp = temp->next;
		i++;
	}
	str[i] = NULL;
	return (str);
}

void	exec_func(char *path, char **arg)
{
	if (execve(path, arg, g_shell->environ) == -1)
	{
		g_shell->exit_status = 127;
		printf("%s: command not found\n", arg[0]);
		free(path);
		exit(127);
	}
}

char	*func_path(char **arg)
{
	char	**path;
	char	*temp;
	int		i;

	i = 0;
	temp = find_env("PATH");
	if (access(arg[0], F_OK) == 0)
		return (arg[0]);
	path = ft_split(temp, ':');
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		path[i] = ft_strjoin(path[i], arg[0]);
		if (access(path[i], F_OK) == 0)
			break ;
		i++;
	}
	return (path[i]);
}

void	other_commands(char **arg)
{
	int	pid;
	int	i;

	i = -1;
	if (access(arg[0], F_OK) == 0)
		g_shell->exit_status = 0;
	else
		g_shell->exit_status = 127;
	pid = fork();
	if (pid == 0)
		exec_func(func_path(arg), arg);
	waitpid(pid, 0, 0);
	if (g_shell->pipe <= 0)
	{
		while (++i < ft_listsize(g_shell->arg))
			free(arg[i]);
		free(arg);
	}
}
