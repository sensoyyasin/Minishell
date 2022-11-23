/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:39:14 by ysensoy           #+#    #+#             */
/*   Updated: 2022/11/21 10:46:50 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_sayici(t_shell *shell)
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

int other_cmnds(char **arg)
{
	int pid;
	int i = 0;
	char **str;

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

t_list	*ft_lstnew(void	*content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!(new))
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*list;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	list = ft_lstlast(*lst);
	list->next = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    if (begin_list == NULL || *begin_list == NULL)
        return;
    t_list *cur = *begin_list;
    if (cmp(cur->data, data_ref, cmp) == 0)
    {
        *begin_list = cur->next;
        free(cur);
        ft_list_remove_if(begin_list, data_ref, cmp);
    }
    cur = *begin_list;
    ft_list_remove_if(&cur->next, data_ref, cmp);
}

// char	*ft_strchr(char *s, int c)
// {
// 	size_t	i;
// 	size_t	a;

// 	a = ft_strlen(s);
// 	i = 0;
// 	while (i <= a)
// 	{
// 		if (s[i] == (char)c)
// 			return ((char *)s + i);
// 		i++;
// 	}
// 	return (NULL);
// }