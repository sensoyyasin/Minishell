#include "minishell.h"

int	lstcmp(char *str)
{
	t_list *temp;

	shell->cmmp = 1;
	temp = shell->asd;
	temp = temp->next;
	while (temp != NULL)
	{
		if (ft_strcmp_z(temp->content, str))
			return (0);
		temp = temp->next;
		shell->cmmp++;
	}
	return(1);
}

int		ft_strcmp_z(char *str, char *str2)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str2[i] != '\0')
	{
		if (str[i] == '=' && str2[i] == '=')
			return(1);
		else if (str[i] == str2[i])
			i++;
		else
			return(0);
	}
	return(1);
}
