/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinsensoy <yasinsensoy@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:41:52 by mtemel            #+#    #+#             */
/*   Updated: 2023/01/08 09:51:29 by yasinsensoy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*strrev(char *c)
{
	int		i;
	int		j;
	char	temp;

	j = ft_strlen(c) - 1;
	i = 0;
	temp = 0;
	while (i < j)
	{
		temp = c [i];
		c[i] = c[j];
		c[j] = temp;
		i++;
		j--;
	}
	return (c);
}

static char	*ia(int n, char *str)
{
	int	i;
	int	temp;

	i = 0;
	temp = n;
	if (temp < 0)
		temp = -temp;
	while (temp > 0)
	{
		str[i] = temp % 10 + 48;
		temp = temp / 10;
		i++;
	}
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	return (str);
}

static size_t	calculateallocate(int n)
{
	size_t	i;
	int		temp;

	i = 0;
	temp = n;
	if (temp < 0)
	{
		temp = -temp;
		i++;
	}
	while (temp > 0)
	{
		temp = temp / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	str = (char *)malloc(sizeof(char) * (calculateallocate(n) + 1));
	if (!str)
		return (0);
	str = ia(n, str);
	str = strrev(str);
	return (str);
}
