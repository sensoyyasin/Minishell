/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:38:45 by ysensoy           #+#    #+#             */
/*   Updated: 2022/11/21 11:38:42 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(t_shell *shell)
{
	if (shell->sayi == 42)
	{
		fill(shell);
		shell->sayi++;
	}
	if (shell->str[1] != NULL)
		ft_lstadd_back(&shell->x, ft_lstnew(shell->str[1]));
}

void	fill(t_shell *shell)
{
	int i;

	i = 0;
	shell->x = malloc(sizeof(t_list) * 50);
	while (environ && environ[i])
	{
		ft_lstadd_back(&shell->x, ft_lstnew(environ[i]));
		i++;
	}
	shell->x = shell->x->next;
}

void	ft_unset(t_shell *shell)
{
	int i;
	int counter;
	char *temp;
	char *temp2;
	t_list *tmp_lst;

	counter = 1;
	i = ft_strlen(shell->str[1]);
	temp = shell->str[1];
	tmp_lst = shell->x; //envlerin hepsini atadım
	tmp_lst = tmp_lst->next; //başı null
	while (tmp_lst != NULL)
	{
		temp2 = tmp_lst->content;
		if (ft_strcmp(temp, temp2))
			ft_remover(shell, counter);
		counter++;
		tmp_lst = tmp_lst->next;
	}
}

void	ft_remover(t_shell *shell, int counter)
{
	t_list *temp;
	t_list *temp2;

	temp = shell->x;
	while (counter > 1)
	{
		temp = temp->next;
		counter--;
	}
	if (temp->next->next != NULL)
		temp2 = temp->next->next;
	else
		temp2 = NULL;
	if (temp2 != NULL)
		temp->next = temp2;
	else
		temp->next = NULL;
}
