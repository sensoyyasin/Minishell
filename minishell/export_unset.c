#include "minishell.h"

/* take environment as node's content */
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
	char	*content;
	char	*content1;

	i = 1;
	content1 = index_data(list ,i);
	if (content1 != NULL)
		content = ft_strdup(content1);//freelenecek
	else
		content = NULL;
	if (!shell->ctrl++)
		ft_fill();
	if (content == NULL)
		printf_alph();
	while (content)
	{
		if (!ft_isalpha(content))
			break;
		if (islistequal(content) == 2)
		{
			i++;
			content = index_data(list, i);
			continue;
		}
		if (islistequal(content) == 3)
		{
			delete_node(&shell->asd, content);
			ft_lstadd_back(&shell->asd, ft_lstnew(content));
		}
		else if (ft_strchr(content, '=') && !islistequal(content))
			ft_lstadd_back(&shell->asd, ft_lstnew(content));
		else if (ft_strchr(content, '=') && islistequal(content))
		{
			delete_node(&shell->asd, content);
			ft_lstadd_back(&shell->asd, ft_lstnew(content));
		}
		else if (!ft_strchr(content, '=') && !isequal(content))
			ft_lstadd_back(&shell->asd, ft_lstnew(content));
		else if (!ft_strchr(content, '=') && isequal(content))
		{
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
	if ((str[i] == '\0' || str[i] == '=') && content[i] == '\0')
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
