#include "minishell.h"

void	ft_fill()
{
	int i;

	i = 0;
	shell->asd= NULL;
	while (shell->environ[i] != NULL)
	{
		ft_lstadd_back(&shell->asd, ft_lstnew(shell->environ[i]));
		i++;
	}
	//! -> alphabetic olarak siralamasi gerek bunun algoritması olusturulacak.
}

void	ft_export(t_list *list)
{
	int		i;
	char	*content;
	char	*content1;

	i = 1;
	content1 = index_data(list ,i);
	if (content1 != NULL)
		content = ft_strdup(content1);
	else
		content = NULL;
	if (!shell->ctrl++)
		ft_fill();
	//printf("%s\n",shell->arg->content); ->export
	//printf("%s\n",shell->arg->next->content); -> a
	if (content == NULL)
		printf_alph();
	while (content)
	{
		if (content == NULL)
			break;
		if (lstcmp(content) && ft_strchr(content, '='))
			ft_lstadd_back(&shell->asd, ft_lstnew(content));
		else if (lstcmp(content) && !ft_strchr(content, '='))
			ft_lstadd_back(&shell->declare, ft_lstnew(content));
		else
		{
			//ft_dstry_node(shell->cmmp);
			if (ft_strchr(content, '='))
				ft_lstadd_back(&shell->asd, ft_lstnew(content));
		}
		i++;
		content = index_data(list, i);
	}
	return;
}

// void	ft_destroy_node(int c)
// {
// 	int i;
// 	t_list *temp;

// 	i = 0;
// 	temp = shell->arg;
// 	while (str != NULL)
// 	{
// 		temp = temp->next;
// 	}

// }

void	printf_alph(void)
{
	t_list *list_iter;
	int i;
	i = 0;
	list_iter = shell->asd; // shell->asd'si kopya listemiz.
	while (list_iter != NULL)
	{
		while (list_iter && list_iter->index != i)
			list_iter = list_iter->next;
		if (list_iter == NULL)
			return;
		if ((char *)list_iter->content)
			printf("declare -x %s\n", list_iter->content);
		i++;
		list_iter = shell->asd;
		continue;
	}
}
