/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:54:07 by mtemel            #+#    #+#             */
/*   Updated: 2022/12/27 16:32:37 by mtemel           ###   ########.fr       */
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
	free (temp);
}

void	ft_cd2(char *pwd)
{
	char	*home;

	home = getenv("HOME");
	if (chdir(home) != 0)
	{
		printf("-> No such file or directory.\n");
		return ;
	}
	cdelete_node(&g_shell->asd, pwd);
	ft_lstadd_back(&g_shell->asd, ft_lstnew(ft_strjoin(pwd, home)));
	return ;
}

int	ft_cd(t_list *list)
{
	char	*pwd;
	char	cwd[1024];

	pwd = ft_strdup("PWD=");
	if (index_data(list, 1) && getcwd(cwd, sizeof(cwd)) != NULL)
	{
		if (chdir(index_data(list, 1)) != 0)
		{
			printf("-> No such file or directory.\n");
			return (0);
		}
		cdelete_node(&g_shell->asd, pwd);
		ft_lstadd_back(&g_shell->asd, ft_lstnew(
				ft_strjoin(pwd, getcwd(cwd, sizeof(cwd)))));
		return (1);
	}
	else if (!index_data(list, 1) && getcwd(cwd, sizeof(cwd)) != NULL)
	{
		ft_cd2(pwd);
		return (1);
	}
	return (0);
}
