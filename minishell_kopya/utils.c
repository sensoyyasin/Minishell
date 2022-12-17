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
	my->content = ft_strdup(content);
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

static char	**spl(char **str, char *s1, char ch, size_t cnt)
{
	size_t	i;
	size_t	len;
	size_t	word;

	word = 0;
	i = 0;
	len = 0;
	while (word < cnt)
	{
		while (s1[i] != '\0' && s1[i] == ch)
			i++;
		while (s1[i] != '\0' && s1[i] != ch)
		{
			len++;
			i++;
		}
		str[word] = ft_substr(s1, i - len, len);
		len = 0;
		word++;
	}
	str[word] = 0;
	return (str);
}

static size_t	cntpp(char *str, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			cnt++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (cnt);
}

char	**ft_split(char *s, char c)
{
	char	**str;
	size_t	cnt;

	if (!s)
		return (0);
	cnt = cntpp(s, c);
	str = (char **)malloc(sizeof(char *) * cnt + 1);
	if (!str)
		return (0);
	spl(str, s, c, cnt);
	return (str);
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

int	ft_isalpha(char *str)
{
	if (str[0] < 65 || (str[0] > 90 && str[0] < 97) || str[0] > 122)
	{
		printf("%s: not a valid identifier\n", str);
		return(0);
	}
	else
		return(1);

}

char	*ft_strrchr(const char *str, int c)
{
	char	*ns;
	int		len;

	ns = (char *)str;
	len = ft_strlen(ns);
	while (len >= 0)
	{
		if (ns[len] == (unsigned char)c)
			return (ns + len);
		len --;
	}
	return (0);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*s1;
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (len == 0 || (start > ft_strlen(s)))
	{
		s1 = (char *)malloc(1);
		*s1 = 0;
		return (s1);
	}
	if (len - start > ft_strlen(s) || start == ft_strlen(s))
		s1 = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		s1 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s1)
		return (0);
	if (start < ft_strlen(s))
	{
		while (*(s + start) && i < len)
			*(s1 + i++) = *(s + start++);
	}
	*(s1 + i) = '\0';
	return (s1);
}
