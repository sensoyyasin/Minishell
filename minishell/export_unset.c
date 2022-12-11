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
		if (ft_strchr(content, '=') && !islistequal(content))
		{
			printf("ilk if çalıştı(= var değişken farklı) step:%d\n", shell->step);
			ft_lstadd_back(&shell->asd, ft_lstnew(content));
		}
		else if (ft_strchr(content, '=') && islistequal(content))
		{
			printf("ikinci if çalıştı(= var değişken aynı) step:%d\n", shell->step);
			delete_node(&shell->asd, content);
			ft_lstadd_back(&shell->asd, ft_lstnew(content));
		}
		else if (!ft_strchr(content, '=') && !isequal(content))
		{
			printf("üçüncü if çalıştı(= yok değişken farklı) step:%d\n", shell->step);
			ft_lstadd_back(&shell->asd, ft_lstnew(content));
		}
		else if (!ft_strchr(content, '=') && isequal(content))
		{
			printf("son if çalıştı(= yok değişken aynı) step:%d\n", shell->step);
			delete_node(&shell->asd, content);
			ft_lstadd_back(&shell->asd, ft_lstnew(content));
		}
		i++;
		content = index_data(list, i);
	}
	return;
}

void	delete_node(t_list **head, char *str)
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
		return;
	}
	while (temp != NULL && !isnamequal(str, temp->content))
	{
		/* printf("i: %d, step: %d\n", i, shell->step); */
		prev = temp;
		temp = temp->next;
		i++;
	}
	if (temp == NULL)
		return ;
	prev->next = temp->next;
	free (temp);
}

int	isnamequal(char *str, char *content)
{
	int	i;

	i = 0;
	if (!str || !content)
		return (0);
	while (str[i] && content[i])
	{
		if(str[i] != content[i])
			return (0);
		if(str[i] == '=' && content[i] == '=')
			return(1);
		i++;
	}
	if (str[i] == '\0' && content[i] == '\0')
		return(1);
	return (0);
}

void	printf_alph(void)
{
	t_list *list_iter;
	int	i;
	int	flag;

	list_iter = shell->asd; // shell->asd'si kopya listemiz.
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
		if(ft_strchr(list_iter->content, '='))
			write(1, "\"", 1);
		write(1, "\n", 1);
		list_iter = list_iter->next;
	}
}
