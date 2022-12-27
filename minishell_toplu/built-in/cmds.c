/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:05:12 by mtemel            #+#    #+#             */
/*   Updated: 2022/12/27 16:32:37 by mtemel           ###   ########.fr       */
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
			printf("%s", index_data(list, i));
			if (f == 0)
				printf("\n");
		}
		else
			printf("%s ", index_data(list, i));
	}
}

void	ft_unset(t_list *list)
{
	int		i;
	char	*content;
	char	*content1;

	i = 1;
	content1 = index_data(list, i);
	if (content1 != NULL)
		content = ft_strdup(content1);
	else
		content = NULL;
	while (content)
	{
		if (islistequal(content) == 2 || isequal(content))
			udelete_node(&g_shell->asd, content);
		i++;
		content = index_data(list, i);
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
			free(temp2);
			return ;
		}
		list = list->next;
		i = 0;
	}
}
