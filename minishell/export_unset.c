#include "minishell.h"

void	ft_fill()
{
	int i;

	i = 0;
	shell->asd= NULL;
	while (shell->environ[i] != NULL)
	{
		ft_lstadd_back(&shell->asd, ft_lstnew(shell->environ[i]));
		ft_lstadd_back(&shell->declare, ft_lstnew(shell->environ[i]));
		i++;
	}
	//! -> alphabetic olarak siralamasi gerek bunun algoritması olusturulacak.
}

void	ft_export(t_list *list)
{
	int		i;
	int		j;
	char	*content;
	char	*content1;

	i = 1;
	j = 0;
	content1 = index_data(list ,i);
	if (content1 != NULL)
		content = ft_strdup(content1);//freelenecek
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
		if (ft_strchr(content, '=') && !lstcmp_isequal(content))// = var ve benzersiz
		{
			printf("ilk if\n");
			ft_lstadd_back(&shell->asd, ft_lstnew(content));
			ft_lstadd_back(&shell->declare, ft_lstnew(content));
		}
		else if (ft_strchr(content, '=') && lstcmp_isequal(content) == 1)// = var ve aynı
		{
			ft_lstadd_back(&shell->asd, ft_lstnew(content));
			ft_lstadd_back(&shell->declare, ft_lstnew(content));
		}
		else if(!lstcmp_isequal(content))// = yok (declare)
		{
			printf("son if\n");
			ft_lstadd_back(&shell->declare, ft_lstnew(content));
		}
		i++;
		content = index_data(list, i);
	}
	return;
}

void	delete_node(char *str)
{
	t_list	**temp;
	int		i;

	temp = &(shell->asd);
	if(!(*temp))
		return ;
	while ((*temp)->next != NULL)
	{
		i = 0;
		while ((*temp)->next->content[i] && str[i])
		{
			if ((*temp)->next->content[i] != str[i])
				break;
			if (((*temp)->next->content[i] == '=' && str[i] == '=') && (!(*temp)->content[i] && !str[i]))
			{
				(*temp)->next = (*temp)->next->next;
			}
			i++;
		}
		*temp = (*temp)->next;
	}
	shell->asd = *temp;
}

void	printf_alph(void)
{
	t_list *list_iter;
	int	i;
	int	flag;

	list_iter = shell->declare; // shell->asd'si kopya listemiz.
	while (list_iter)
	{
		write(1, "declare -x ", 11);
		i = 0;
		flag = 0;
		while(list_iter->content[i])
		{
			write(1, &list_iter->content[i], 1);
			if(list_iter->content[i] == '=' && flag == 0)
			{
				flag = 1;
				write(1, "\"", 1);
			}
			i++;
		}
		write(1, "\"", 1);
		write(1, "\n", 1);
		list_iter = list_iter->next;
	}
}
