#include "minishell.h"

int		right_single_counter()
{
	t_list *iter;

	iter = shell->arg;
	shell->right_single_counter = 0;
	while (iter != NULL)
	{
		if (ft_strcmp(iter->content, ">") && !ft_strcmp(iter->next->content, ">"))
			shell->right_single_counter++;
		iter = iter->next;
	}
	return(shell->right_single_counter);
}

int		right_double_counter()
{
	t_list *iter;

	iter = shell->arg;
	shell->right_double_counter = 0;
	while (iter != NULL)
	{
		if (ft_strcmp(iter->content, ">>") && !ft_strcmp(iter->next->content, ">") && !ft_strcmp(iter->next->content, "<"))
			shell->right_single_counter++;
		iter = iter->next;
	}
	return(shell->right_single_counter);
}

int		left_single_counter()
{
	t_list	*iter;

	iter = shell->arg;
	shell->left_single_counter = 0;
	while (iter != NULL)
	{
		if (ft_strcmp(iter->content, "<") && !ft_strcmp(iter->next->content, "<") && !ft_strcmp(iter->next->content, ">"))
			shell->left_single_counter++;
		iter = iter->next;
	}
	return(shell->left_single_counter);
}
