#include "minishell.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		a;
	char	*dizi;

	if (!s1)
	{
		s1 = (char*)malloc(1);
		s1[0] = '\0';
	}
	if (!s2)
		return(NULL);
	dizi = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dizi)
		return (0);
	i = -1;
	while (s1[++i] != '\0')
		dizi[i] = s1[i];
	a = -1;
	while (s2[++a] != '\0')
		dizi[i + a] = s2[a];
	dizi[i + a] = '\0';
	free(s1);
	return (dizi);
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	int		len;
	int		i;

	len = ft_strlen(s1);
	s2 = malloc(sizeof(char) * len + 1);
	if (s2 == NULL)
		return(NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return(s2);
}

char	*ft_strchr(const char *s, int x)
{
	if (x > 127)
		return ((char *)s);
	while (*s)
	{
		if (*s == x)
			return ((char *)s);
		++s;
	}
	if (x == '\0')
		return ((char *)s);
	return (0);
}

t_list	*ft_lstnew(void *content)
{
	t_list *my;

	my = (t_list *)malloc(sizeof(t_list));
	if (!my)
		return(NULL);
	my->content = content;
	my->next = NULL;
	return(my);
}

void	free_list(void)
{
	while (shell->arg != NULL)
	{
		free(shell->arg->content);
		free(shell->arg);
		shell->arg = shell->arg->next;
	}
}

int		ft_listsize(t_list *list)
{
	int i;

	i = 0;
	while (list != NULL)
	{
		list = list->next;
		i++;
	}
	return(i);
}

static size_t	wordcounter(char *ptr, char c)
{
	size_t counter;

	counter = 0;
	if (!ptr)
        return(0);
    while (*ptr)
    {
        while (*ptr && *ptr == c)
            ptr++;
        if (*ptr)
            counter++;
        while (*ptr && *ptr != c)
            ptr++;
    }
    return(counter);
}

static size_t  word_len(char *ptr, char c)
{
    size_t    count;

    count = 0;
    while (ptr && *ptr && *(ptr++) != c)
        count++;
    return (count);
}

char    **ft_split(char	*ptr, char c)
{
    char	**temp;
    char	**holdtemp;
    char    *str;
    char    wordcount;

    wordcount = wordcounter(ptr, c);
    if (!wordcount)
        return (NULL);
    temp = (char**)malloc(sizeof(char *) * (wordcount + 1));
    holdtemp = temp;
    while (*ptr)
    {
        while (*ptr == c)
            ptr++;
        if (!(*ptr))
            break;
        str = (char *)malloc(sizeof(char) * (word_len(ptr, c) + 1));
        *(temp++) = str;
        while(*ptr != c && *ptr)
            *(str++) = *(ptr++);
        *str = 0;
    }
    *temp = NULL;
    return (holdtemp);
}

int	ft_strcmp2(char *asd, char *sda)
{
	int	i;
	size_t len;

	len = ft_strlen(sda);
	i = 0;
	while (len)
	{
		if (asd[i] == sda[i])
			i++;
		else
			return(0);
		len--;
	}
	if (asd[i] == '=')
		return(1);
	else
	{
		printf("minishell: unset: `%s': not a valid identifier\n", asd);
		return(0);
	}
}

void	ft_putstr_fd(char *str, int fd)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			write(fd, &str[i], 1);
			i++;
		}
	}
}

void	reset_stdout()
{
	dup2(shell->saved_stdout, 1);
	close(shell->saved_stdout);
}
