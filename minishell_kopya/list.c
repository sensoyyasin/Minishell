#include "minishell.h"

int	islistequal(char *str)
{
	t_list	*temp;
	int		i;

	shell->step = 0;
	temp = shell->asd;
	if (!temp)
		return (0);
	while (temp)
	{
		i = 0;
		while (temp->content[i] && str[i])
		{
			if(temp->content[i] != str[i])
				break ;
			if(temp->content[i] == '=' && str[i] == '=')
				return(1);
			i++;
		}
		if(temp->content[i] == '=' && str[i] == '\0')
			return (2);
		if(temp->content[i] == '\0' && str[i] == '=')
			return (3);
		temp = temp->next;
		(shell->step)++;
	}
	return (0);
}

int	isequal(char *str)
{
	t_list	*temp;
	int		i;

	shell->step = 0;
	temp = shell->asd;
	if (!temp)
		return (0);
	while (temp)
	{
		i = 0;
		while (temp->content[i] && str[i])
		{
			if(temp->content[i] != str[i])
				break ;
			i++;
		}
		if (temp->content[i] == '\0' && str[i] == '\0')
			return(1);
		temp = temp->next;
		(shell->step)++;
	}
	return (0);
}

int	ft_lstcmp(t_list *iter, char *str)
{
	t_list	*temp;

	temp = iter;
	while (temp != NULL)
	{
		if (ft_strcmp(temp->content, str))
			return(0);
		temp = temp->next;
	}
	return(1);
}

void	udelete_node(t_list **head, char *str)
{
	t_list	*temp;
	t_list	*prev;
	int		i;

	i = 0;
	temp = *head;
	prev = *head;
	if (temp != NULL && shell->step == 0)
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

int	uisnamequal(char *str, char *content)
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
	if ((str[i] == '\0' || str[i] == '=')
		&& (content[i] == '=' || content[i] == '\0'))
		return (1);
	return (0);
}
