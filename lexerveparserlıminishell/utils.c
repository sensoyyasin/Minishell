#include "minishell.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		a;
	char	*src;
	char	*dest;
	char	*dizi;

	i = 0;
	a = 0;
	src = (char *)s1;
	if (!s1)
		return (0);
	dest = (char *)s2;
	dizi = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)));
	if (!dizi)
		return (0);
	while (src[i] != '\0')
	{
		dizi[i] = src[i];
		i++;
	}
	while (dest[a] != '\0')
		dizi[i++] = dest[a++];
	dizi[i] = '\0';
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
