#include "minishell.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return(i);
}

int ft_strcmp(char *x, char *y)
{
    int i = 0;
    size_t len;

    len = ft_strlen(y);
    while (len)
    {
        if (x[i] == y[i])
            i++;
        else
            return(0);
        len--;
    }
    if (x[i] != '\0')
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
