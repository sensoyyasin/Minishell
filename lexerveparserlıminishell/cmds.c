#include "minishell.h"

void	 ft_echo(t_list *list)
{
	char	*content;
	int	i;

	i = 1;
	if (index_data(list, i) == NULL)
		printf("\n");
	else
	{
		content = index_data(list, i);
		while (content != NULL)
		{
			if (ft_strcmp(content, "-n") && index_data(list, i + 1) == NULL && i == 1)
				return ;
			if (ft_strcmp(content, "-n") && index_data(list, i + 1) != NULL)
			{
				printf("%s", index_data(list, i + 1));
				i++;
			}
			else if (index_data(list, i + 1) == NULL)
				printf("%s\n", content);
			else
				printf("%s ", content);
			i++;
			content = index_data(list, i);
		}
	}
}

void	ft_lstclear(t_list *lst)
{
	t_list	*temp;

	if (lst == NULL)
		return ;
	while (lst)
	{
		temp = lst->next;
		if (!lst)
			return ;
		free(lst);
		lst = temp;
	}
}

void	ft_unset(t_list *list)
{
	ft_lstclear(list);
}

int		ft_env(void)
{
	t_list	*temp;

	if (!shell->ctrl)
	{
		ft_fill();
		shell->ctrl++;
	}
	temp = shell->asd;
	while (temp != NULL)
	{
		printf("%s\n",temp->content);
		temp = temp->next;
	}
	return(1);
}

void	ft_pwd(void)
{
	t_list	*list;
	char	*temp;
	char	*temp2;
	int		i;

	if (!shell->asd)
		ft_fill();
	i = 0;
	list = shell->asd;
	temp2 = malloc(ft_strlen("PWD") + 1);
	while (list != NULL)
	{
		temp = list->content; // -> Mesela ilkinde USE ' yi attı ilk satırın ilk 3 üne bakıyor.
		while (temp[i] != '=' && i < 3)
		{
			temp2[i] = temp[i];
			i++;
		}
		temp2[i] = '\0';
		if (ft_strcmp(temp2, "PWD")) // -> karsilastirma yapiyor.
		{
			printf("%s\n", &temp[++i]); // -> ='den sonraki yerin komple adresini dönüyoruz cunku komple satırı getirsin diye
			free(temp2);
			return ;
		}
		list = list->next;
		i = 0;
	}
}
