/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:45:42 by ysensoy           #+#    #+#             */
/*   Updated: 2022/10/27 17:29:45 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_sayici(t_list *shell)
{
	int i;
	int j;

	i = 0;
	shell->pipe = 0;
	while (shell->str[i])
	{
		j = 0;
		while (shell->str[i][j])
		{
			if (shell->str[i][j] == '|')
				shell->pipe++;
			j++;
		}
		i++;
	}
}

int ft_strlen(const char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return(i);
}

char	*to_lower(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
			i++;
	}
	return(str);
}

int ft_strncmp(char *str1, char *str2, size_t n)
{
	size_t i;

	i = 0;
	while (str1[i] == str2[i] && (str1[i] != '\0' || str2[i] != '\0'))
		i++;
	if (i >= n)
		return(1);
	else
		return(0);
}
char	*ft_strdup(const char *s1)
{
	int		i;
	char	*src;
	char	*dest;

	i = 0;
	src = (char *)s1;
	dest = (char *)malloc(ft_strlen(src) + 1);
	if (dest == 0)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


int other_cmnds(char **arg)
{
	int pid;
	int i = 0;
	char **str;
	extern char **environ;

	str = ft_split(ft_strdup(getenv("PATH")),':');
	while (str[i])
	{
		str[i] = ft_strjoin(str[i], "/");
		str[i] = ft_strjoin(str[i], arg[0]);
		if (access(str[i], F_OK) == 0)
			break;
		i++;
	}
	pid = fork();
	if (pid == 0)
	{
		if(execve(str[i], arg, environ) == -1)
		{
			printf("zsh: command not found\n");
			exit(0);
		}
	}
	wait(NULL);
	return (1);
}

int ft_strcmp(char *str1, char *str2)
{
	int i;

	i = 0;
	if (!str1)
		return(0);
    while (str1[i] == str2[i])
    {
        if(!str1[i] && !str2[i])
			return(1);
		i++;
    }
    return(0);
}

char	*ft_strjoin(char const *s1, char const *s2)
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
