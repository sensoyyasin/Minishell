/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:38:38 by ysensoy           #+#    #+#             */
/*   Updated: 2022/11/21 10:38:39 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
