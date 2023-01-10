/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:54:07 by mtemel            #+#    #+#             */
/*   Updated: 2023/01/10 21:49:40 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cdelete_node(t_list **head, char *str)
{
	t_list	*temp;
	t_list	*prev;
	int		i;

	i = 0;
	temp = *head;
	prev = *head;
	if (temp != NULL && uisnamequal(str, temp->content))
	{
		*head = temp->next;
		free (temp->content);
		free(temp);
		return ;
	}
	while (temp != NULL && !uisnamequal(str, temp->content))
	{
		prev = temp;
		temp = temp->next;
		i++;
	}
	if (temp == NULL)
		return ;
	prev->next = temp->next;
	free (temp->content);
	free (temp);
}

void	ft_cd2(char *pwd)
{
	char	*home;
	char	*a;

	home = getenv("HOME");
	if (chdir(home) != 0)
	{
		printf("-> No such file or directory.\n");
		g_shell->exit_status = 127;
		return ;
	}
	cdelete_node(&g_shell->asd, pwd);
	a = ft_strjoin(pwd, home);
	ft_lstadd_back(&g_shell->asd, ft_lstnew(a));
	free (a);
	return ;
}

void	ft_cd_norm(char **pwd, char **a)
{
	cdelete_node(&g_shell->asd, *pwd);
	ft_lstadd_back(&g_shell->asd, ft_lstnew(*a));
	free(*a);
}

int	ft_cd(t_list *list)
{
	char	*pwd;
	char	cwd[1024];
	char	*a;

	pwd = ft_strdup("PWD=");
	if (index_data(list, 1) && getcwd(cwd, sizeof(cwd)) != NULL)
	{
		if (chdir(index_data(list, 1)) != 0)
		{
			free(pwd);
			printf("-> No such file or directory.\n");
			g_shell->exit_status = 127;
			return (0);
		}
		a = ft_strjoin(pwd, getcwd(cwd, sizeof(cwd)));
		ft_cd_norm(&pwd, &a);
		return (1);
	}
	else if (!index_data(list, 1) && getcwd(cwd, sizeof(cwd)) != NULL)
	{
		ft_cd2(pwd);
		return (1);
	}
	return (0);
}
