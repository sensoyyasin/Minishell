#include "minishell.h"

// int		redirections_counter()
// {
// 	int		i = 0;
// 	t_list	*iter;

// 	iter = shell->arg;
// 	while (iter != NULL)
// 	{
// 		if (ft_strcmp(iter->content, "<") || ft_strcmp(iter->content, ">"))
// 		{
// 			if (ft_strcmp(iter->content, "<"))
// 				shell->left_single_counter++;
// 			else if (ft_strcmp(iter->content, ">") && !ft_strcmp(iter->next->content, ">"))
// 				shell->right_single_counter++;
// 			else if (ft_strcmp(iter->content, ">") && ft_strcmp(iter->next->content, ">"))
// 				shell->right_double_counter++;
// 			i++;
// 		}
// 		iter = iter->next;
// 	}
// 	return (i);
// }

// int		index_redirect(char *str)
// {
// 	int		i;
// 	t_list	*temp;

// 	i = 0;
// 	temp = shell->arg;
// 	while (temp != NULL)
// 	{
// 		if (ft_strcmp(temp->content, str))
// 			return(i);
// 		i++;
// 		temp = temp->next;
// 	}
// 	return(0);
// }
