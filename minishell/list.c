#include "minishell.h"

int	lstcmp_isequal(char *str)
{
	t_list *temp;
	int	i = 0;

	shell->cmmp = 1;
	temp = shell->asd;
	while (temp != NULL)
	{
		i = 0;
		while (temp->content[i] && str[i])
		{
			if (temp->content[i] != str[i])
				break;
			if ((temp->content[i] == '=' && str[i] == '='))
			{
				while (temp->content[i] == str[i])
				{
					i++;
					if (temp->content[i] == '\0')
						return 2; //değismeyecek
				}

				return (1); //degisecek
			}
			i++;
		}
		temp = temp->next;
		shell->cmmp++;
	}
	return(0);
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
