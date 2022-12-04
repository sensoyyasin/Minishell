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

// void	ft_unset(t_list *list)
// {
// 	ft_lstremover(list); //! ->listeden bulduğunu silmesi gerekiyor.
// }

void	ft_export(t_list *list)
{
	int		i;
	char	*content;

	i = 1;
	content = index_data(list ,i);
	if (!shell->ctrl++)
		ft_fill();
	if (content == NULL)
	{
		if (!shell->ctrl++)
			ft_fill();
		printf_alph();
	}
	while (content)
	{
		if (lstcmp(content) && ft_strchr(content, '='))
			ft_lstadd_back(&shell->asd, ft_lstnew(content));
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
