/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:54:47 by mtemel            #+#    #+#             */
/*   Updated: 2023/01/10 19:59:13 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
		free(temp->content);
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
	free (temp->content);
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
		free(temp->content);
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
	free (temp->content);
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

char	*find_env(char *str)
{
	t_list	*temp;
	int		i;

	temp = g_shell->asd;
	while (temp)
	{
		i = 0;
		while (temp->content[i] && str[i])
		{
			if (temp->content[i] != str[i])
				break ;
			if (temp->content[i] == '=' && str[i] == '=')
				return (temp->content);
			i++;
		}
		if (temp->content[i] == '=' && str[i] == '\0')
			return (temp->content);
		temp = temp->next;
	}
	return (0);
}
