/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:41:52 by mtemel            #+#    #+#             */
/*   Updated: 2022/12/27 16:32:37 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

void	reset_stdout(void)
{
	dup2(g_shell->saved_stdout, 1);
	close(g_shell->saved_stdout);
}

int	ft_isalpha(char *str)
{
	if (str[0] < 65 || (str[0] > 90 && str[0] < 97) || str[0] > 122)
	{
		printf("%s: not a valid identifier\n", str);
		return (0);
	}
	else
		return (1);
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
