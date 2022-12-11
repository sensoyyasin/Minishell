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

void	ft_unset(t_list *list)
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
	while (content)
	{
		if (islistequal(content) == 2 || isequal(content))
			udelete_node(&shell->asd, content);
		i++;
		content = index_data(list, i);
	}
	return;
}

void	udelete_node(t_list **head, char *str)
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
	while (temp != NULL && !uisnamequal(str, temp->content))
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

int	uisnamequal(char *str, char *content)
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
	if ((str[i] == '\0' || str[i] == '=') && (content[i] == '=' || content[i] == '\0'))
		return(1);
	return (0);
}

/* void ft_dstry_node(int c)
{
	t_list *tmp;
	t_list *tmp2;

	tmp = shell->asd;
	tmp2 = shell->asd;
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
} */

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
		if(ft_strchr(temp->content, '='))
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
