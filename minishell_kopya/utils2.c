/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:41:52 by mtemel            #+#    #+#             */
/*   Updated: 2022/12/21 16:46:35 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_listsize(t_list *list)
{
	int	i;

	i = 0;
	while (list != NULL)
	{
		list = list->next;
		i++;
	}
	return (i);
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
	int		i;
	size_t	len;

	len = ft_strlen(sda);
	i = 0;
	while (len)
	{
		if (asd[i] == sda[i])
			i++;
		else
			return (0);
		len--;
	}
	if (asd[i] == '=')
		return (1);
	else
	{
		printf("minishell: unset: `%s': not a valid identifier\n", asd);
		return (0);
	}
}
