#include "minishell.h"

void	d_quote(int index)
{
	char	*content;
	char	*temp;
	char	*ret_dolar;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = malloc(500); // ->  must use free.
	content = index_data(shell->arg, index);
	while (content[i])
	{
		if (content[i] == D_QUOTE)
			i++;
		if (content[i] == '$')
		{
			i++;
			ret_dolar = dollar_sign(content, i);
			while(content[i] != 32 && content[i] != '$' && content[i] != '\0' && content[i] != D_QUOTE && content[i] != S_QUOTE)
				i++;
			while (*ret_dolar)
			{
				temp[j] = (*ret_dolar);
				ret_dolar++;
				j++;
			}
			temp[j] = '\0';
		}
		else
		{
			temp[j] = content[i];
			i++;
			j++;
		}
	}
	temp[j] = '\0';
	list_f_data(shell->arg, index)->content = ft_strdup(temp);
	free(temp);
}

char	*dollar_sign(char *str, int j)
{
	char	*tmp2;
	int	i = 0;

	tmp2 = malloc(size_finder(str, j) + 1);
	while (str[j] != '\0' && str[j] != 32 && str[j] != D_QUOTE && str[j] != '$' && str[j] != S_QUOTE)
	{
		tmp2[i] = str[j];
		i++;
		j++;
	}
	tmp2[i] = '\0';
	shell->temp = ft_strdup(tmp2);
	free(tmp2);
	if (check_env())
		return (check_env());
	return ("");
}

int	size_finder(char *str, int j)
{
	while (str[j] != '\0' && str[j] != 32 && str[j] != D_QUOTE && str[j] != '$')
		j++;
	return (j);
}
