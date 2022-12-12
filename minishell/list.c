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
