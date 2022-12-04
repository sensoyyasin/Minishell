#include "minishell.h"

static void ft_dstry_node(int c)
{
	t_list *tmp;
	t_list *tmp2;

	tmp = shell->arg;
	tmp2 = shell->arg;
	while (c > 1 && tmp != NULL)
	{
		if (tmp->next != NULL)
			tmp = tmp->next;
		c--;
	}
	if (tmp->next->next != NULL)
		tmp2 = tmp->next->next;
	else
		tmp2 = NULL;
	if (tmp2 != NULL)
		tmp->next = tmp2;
	else
		tmp->next = NULL;
}

static char *lstwhere(int i)
{
	t_list *iter;

	iter = shell->arg;
	while(i > 0)
	{
		iter = iter->next;
		i--;
	}
	return(iter->content);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*my;

	my = (t_list *)malloc(sizeof(t_list));
	if (!my)
		return (NULL);
	my -> content = content;
	my -> next = NULL;
	return (my);
}

void here_doc(int i)
{
	char *str;
	char *eof;
	t_list *iter;
	eof = "EOF";
	ft_lstadd_front(&shell->arg, ft_lstnew(lstwhere(i + 1)));
	ft_dstry_node(i + 2);
	ft_lstadd_front(&shell->arg, ft_lstnew(lstwhere(i + 1)));
	ft_dstry_node(i + 2);
	ft_lstadd_front(&shell->arg, ft_lstnew(lstwhere(i + 1)));
	ft_dstry_node(i + 2);
	iter = shell->arg;
	printf("--------------------\n");
	while (iter != NULL)
	{
		printf("1/ %s\n", iter->content);
		iter = iter->next;
	}
	i++;
	while (1)
	{
		str = readline(">");
		if (!ft_strcmp(str, eof))
			ft_lstadd_front(&shell->arg, ft_lstnew(str));
		else
			return;
	}
}
