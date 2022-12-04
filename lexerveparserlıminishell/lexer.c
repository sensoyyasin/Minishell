#include "minishell.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return(i);
}

int ft_strcmp(char *str, char *str2)
{
	int	i = 0;
	size_t	len;

	len = ft_strlen(str2);
	while (len)
	{
		if (str[i] == str2[i])
			i++;
		else
			return(0);
		len--;
	}
	if (str[i] != '\0')
		return(0);
	return(1);
}

int token_compr(void)
{
	int i;

	i = 0;
	if (shell->line[i] == '>' || shell->line[i] == '<' || shell->line[i] == '|')
	{
		if ((shell->line[i] == '>' && shell->line[i + 1] == '>') || (shell->line[i] == '<' && shell->line[i + 1] == '<'))
			return(2);
		else
			return(1);
	}
	return(0);
}

int text_cmpr(void)
{
    int i = 0;

	while ((shell->line[i] != ' ' && shell->line[i] != '\0') && (shell->line[i] != '>' && shell->line[i] != '<' && shell->line[i] != '|'))
    {
        if (shell->line[i] == 34)
        {
            i++;
            while (shell->line[i] != 34 && shell->line[i])
                i++;
            while (shell->line[i] != ' ' && shell->line[i] != '\0')
                i++;
            return(i + 1);
        }
        if (shell->line[i] == 39)
        {
            i++;
            while (shell->line[i] != 39 && shell->line[i] != '\0')
                i++;
            while (shell->line[i] != ' ' && shell->line[i] != '\0')
                i++;
            return(i + 1);
        }
        i++;
    }
    return(i);
}

char	*index_data(t_list *list, int index)
{
	int i = 0;
	t_list *temp;

	if (list == NULL)
		return(0);
	temp = list;
	while (i != index)
	{
		i++;
		temp = temp->next;
	}
	if (temp == NULL)
		return(0);
	return(temp->content);
}
