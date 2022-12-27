/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:45:47 by mtemel            #+#    #+#             */
/*   Updated: 2022/12/27 16:32:37 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* take environment as nodes' content */
void	ft_fill(void)
{
	int	i;

	i = 0;
	g_shell->asd = NULL;
	while (g_shell->environ[i] != NULL)
	{
		ft_lstadd_back(&g_shell->asd, ft_lstnew(g_shell->environ[i]));
		i++;
	}
}

void	export_checker(char *content)
{
	if (islistequal(content) == 3)
	{
		delete_node(&g_shell->asd, content);
		ft_lstadd_back(&g_shell->asd, ft_lstnew(content));
	}
	else if (ft_strchr(content, '=') && !islistequal(content))
		ft_lstadd_back(&g_shell->asd, ft_lstnew(content));
	else if (ft_strchr(content, '=') && islistequal(content))
	{
		delete_node(&g_shell->asd, content);
		ft_lstadd_back(&g_shell->asd, ft_lstnew(content));
	}
	else if (!ft_strchr(content, '=') && !isequal(content))
		ft_lstadd_back(&g_shell->asd, ft_lstnew(content));
	else if (!ft_strchr(content, '=') && isequal(content))
	{
		delete_node(&g_shell->asd, content);
		ft_lstadd_back(&g_shell->asd, ft_lstnew(content));
	}
}

void	ft_export(t_list *list)
{
	int (i) = 1;
	if (index_data(list, i) == NULL)
		printf_alph();
	while (index_data(list, i))
	{
		if (!ft_isalpha(index_data(list, i)))
			break ;
		if (islistequal(index_data(list, i)) == 2)
		{
			i++;
			continue ;
		}
		export_checker(index_data(list, i));
		i++;
	}
	return ;
}

void	printf_alph(void)
{
	t_list	*list_iter;
	int		i;
	int		flag;

	list_iter = g_shell->asd;
	while (list_iter)
	{
		write(1, "declare -x ", 11);
		i = 0;
		flag = 0;
		while (list_iter->content[i])
		{
			write(1, &list_iter->content[i], 1);
			if (list_iter->content[i] == '=' && flag == 0)
			{
				flag = 1;
				write(1, "\"", 1);
			}
			i++;
		}
		if (ft_strchr(list_iter->content, '='))
			write(1, "\"", 1);
		write(1, "\n", 1);
		list_iter = list_iter->next;
	}
}
