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



// int		ft_strcmp_z(char *str, char *str2)
// {
// 	int i;

// 	i = 0;
// 	while (str[i] != '\0' && str2[i] != '\0')
// 	{
// 		if (str[i] == '=' && str2[i] == '=')
// 			return(1);
// 		else if (str[i] == str2[i])
// 			i++;
// 		else
// 			return(0);
// 	}
// 	return(1);
// }
