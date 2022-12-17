#include "minishell.h"

void	expand(int index)
{
	char	*content;
	char	*temp;
	temp = malloc(500);
	int i = 0;
	int j = 0;

	content = index_data(shell->arg, index);
	while (content[i])
	{
		if (content[i] == '$')
		{
			temp = ft_strjoin(temp, dollar_sign(content, ++i));
			while (content[i] != 32 && content[i] != '$' && content[i] != '\0')
				i++;
			while (j < ft_strlen(temp))
				j++;
		}
		temp[j++] = content[i++];
	}
	temp[j] = '\0';
	list_f_data(shell->arg, index)->content = ft_strdup(temp);
	free(temp);
}

void	expander()
{
	t_list	*iter;
	char	*content;
	int		quote_varmi;
	int		index;

	index = 0;
	iter = shell->arg;
	while (iter != NULL)
	{
		content = ft_strdup(iter->content);
		quote_varmi = quote_check(content);
		if (quote_varmi == D_QUOTE)
			d_quote(index);
		else if (quote_varmi == S_QUOTE)
			s_quote(index);
		else
			expand(index);
		iter = iter->next;
		index++;
		free(content);
	}
}

void	s_quote(int index)
{
	char	*content;
	char	*temp;
	int		i;
	int		j;

	temp = malloc(500);
	i = 0;
	j = 0;
	content = index_data(shell->arg, index);
	if (content[i] == S_QUOTE)
	{
		i++;
		while (content[i] && content[i] != S_QUOTE)
		{
			temp[j] = content[i];
			i++;
			j++;
		}
		while (content[++i])
			temp[j++] = content[i];
		temp[j] = '\0';
	}
	list_f_data(shell->arg, index)->content = ft_strdup(temp);
	free(temp);
}

t_list  *list_f_data(t_list *root, int index)
{
	t_list *list;
	int i;

	if (!root)
		return(NULL);
	list = root;
	i = 0;
	while (i != index)
	{
		i++;
		list = list->next;
	}
	return(list);
}

int	quote_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == D_QUOTE)
			return(D_QUOTE);
		else if (str[i] == S_QUOTE)
			return(S_QUOTE);
		i++;
	}
	return(0);
}
