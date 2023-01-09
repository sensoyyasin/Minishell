/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:05:12 by mtemel            #+#    #+#             */
/*   Updated: 2023/01/09 17:05:55 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_echo(t_list *list)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	while (index_data(list, ++i) != NULL)
	{
		while (f == i - 1 && ft_strcmp(index_data(list, i), "-n"))
		{
			i++;
			f++;
		}
		if (index_data(list, i) == NULL)
			return ;
		if (index_data(list, i + 1) == NULL)
		{
			g_shell->exit_status = 0;
			printf("%s", index_data(list, i));
			if (f == 0)
				printf("\n");
		}
		else
			printf("%s ", index_data(list, i));
	}
	g_shell->exit_status = 0;
}

void	ft_unset(t_list *list)
{
	int		i;

	i = 1;
	while (index_data(list, i))
	{
		if (islistequal(index_data(list, i)) == 2
			|| isequal(index_data(list, i)))
			udelete_node(&g_shell->asd, index_data(list, i));
		g_shell->exit_status = 0;
		i++;
	}
	return ;
}

int	ft_env(void)
{
	t_list	*temp;

	if (!g_shell->ctrl)
	{
		ft_fill();
		g_shell->ctrl++;
	}
	temp = g_shell->asd;
	while (temp != NULL)
	{
		if (ft_strchr(temp->content, '='))
			printf("%s\n", temp->content);
		g_shell->exit_status = 0;
		temp = temp->next;
	}
	return (1);
}

void	ft_pwd(void)
{
	t_list	*list;
	char	*temp2;
	int		i;

	i = 0;
	list = g_shell->asd;
	temp2 = malloc(ft_strlen("PWD") + 1);
	while (list != NULL)
	{
		while (list->content[i] != '=' && i < 3)
		{
			temp2[i] = list->content[i];
			i++;
		}
		temp2[i] = '\0';
		if (ft_strcmp(temp2, "PWD"))
		{
			printf("%s\n", &list->content[++i]);
			g_shell->exit_status = 0;
			free(temp2);
			return ;
		}
		list = list->next;
		i = 0;
	}
}
