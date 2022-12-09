#include "minishell.h"

char	*check_env(void)
{
	t_list	*t_temp;
	char	*temp;
	char	*temp2;
	int		i;

	if (!shell->asd)
		ft_fill();
	t_temp = shell->asd;
	while (t_temp != NULL)
	{
		temp = ft_strdup(t_temp->content);
		i = 0;
		while (temp[i] != '=')
			i++;
		temp2 = malloc(sizeof(char *) * (i) + 1);
		i = 0;
		while (temp[i] != '=')
		{
			temp2[i] = temp[i];
			i++;
		}
		temp2[i] = '\0';
		if (ft_strcmp(temp2, shell->temp))
			return(ret_env(i + 1, temp));
		t_temp = t_temp->next;
	}
	free(temp);
	free(temp2);
	return(NULL);
}

char	*ret_env(int i, char *str)
{
	char	*ret;
	int		j;

	int len = 0;
	j = i;
	while (str[j])
	{
		j++;
		len++;
	}
	ret = malloc(sizeof(char *) * (j + 1));
	j = 0;
	while (str[i])
		ret[j++] = str[i++];
	ret[j] = '\0';
	return(ret);
}