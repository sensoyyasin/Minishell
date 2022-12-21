/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:54:47 by mtemel            #+#    #+#             */
/*   Updated: 2022/12/21 14:05:14 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_node(t_list **head, char *str)
{
	t_list	*temp;
	t_list	*prev;
	int		i;

	i = 0;
	temp = *head;
	prev = *head;
	if (temp != NULL && g_shell->step == 0)
	{
		*head = temp->next;
		free(temp);
		return ;
	}
	while (temp != NULL && !isnamequal(str, temp->content))
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

int	isnamequal(char *str, char *content)
{
	int	i;

	i = 0;
	if (!str || !content)
		return (0);
	while (str[i] && content[i])
	{
		if (str[i] != content[i])
			return (0);
		if (str[i] == '=' && content[i] == '=')
			return (1);
		i++;
	}
	if ((str[i] == '\0' || str[i] == '=') && content[i] == '\0')
		return (1);
	return (0);
}

void	hdelete_node(t_list **head, char *str)
{
	t_list	*temp;
	t_list	*prev;

	temp = *head;
	prev = *head;
	if (temp != NULL && hisnamequal(str, temp->content))
	{
		*head = temp->next;
		free(temp);
		return ;
	}
	while (temp != NULL && !hisnamequal(str, temp->content))
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return ;
	prev->next = temp->next;
	free (temp);
}

int	hisnamequal(char *str, char *content)
{
	int	i;

	i = 0;
	if (!str || !content)
		return (0);
	while (str[i] && content[i])
	{
		if (str[i] != content[i])
			return (0);
		i++;
	}
	if (str[i] == '\0' && content[i] == '\0')
		return (1);
	return (0);
}
