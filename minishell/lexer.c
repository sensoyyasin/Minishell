#include "minishell.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return(i);
}

/* return 1 if strings equal
return 0 if there is any difference */
int ft_strcmp(char *str, char *str2)
{
	int	i = 0;
	size_t	len;

	len = ft_strlen(str2);
	if (!str)
		return (0);
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

int token_compare(void)
{
	int i;

	i = 0;
	if (shell->line[i] == '>' || shell->line[i] == '<' || shell->line[i] == '|')
	{
		if ((shell->line[i] == '>' && shell->line[i + 1] == '>') || (shell->line[i] == '<' && shell->line[i + 1] == '<'))
			return(2);
		else if ((shell->line[i + 1] == '>' && shell->line[i + 2] == '>') || (shell->line[i + 2] == '<' && shell->line[i + 1] == '<'))
		{
			write(2, "syntax error near unexpected token\n", 35);
			return(-1);
		}
		else if (shell->line[i + 1] == '<' || shell->line[i + 1] == '>')
		{
			write(2, "syntax error near unexpected token\n", 35);
			return(-1);
		}
		else if (shell->line[i] == '|' && shell->line[i + 1] == '|')
		{
			write(2, "syntax error near expected token '||'\n", 38);
			return (-1);
		}
		else
			return(1);
	}
	return(0);
}

int text_cmpr(void)
{
    int i;

	i = 0;
	while ((shell->line[i] != ' ' && shell->line[i] != '\0') && (shell->line[i] != '>' && shell->line[i] != '<' && shell->line[i] != '|'))
    {
        if (shell->line[i] == D_QUOTE)
        {
            i++;
            while (shell->line[i] != D_QUOTE && shell->line[i])
                i++;
            while (shell->line[i] != ' ' && shell->line[i] != '\0')
                i++;
            return(i + 1);
        }
        if (shell->line[i] == S_QUOTE)
        {
            i++;
            while (shell->line[i] != S_QUOTE && shell->line[i] != '\0')
                i++;
            while (shell->line[i] != ' ' && shell->line[i] != '\0')
                i++;
            return(i + 1);
        }
        i++;
    }
    return(i);
}

/* return command's next argument as char* */
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
	{
		return(0);
	}
	return(temp->content);
}
