/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinsensoy <yasinsensoy@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:43:06 by mtemel            #+#    #+#             */
/*   Updated: 2023/01/08 14:57:02 by yasinsensoy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_siginit(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	signal_d(void)
{
	printf("exit\n");
	exit(1);
}

char	*rl_gets(char *str)
{
	if (str)
		free(str);
	str = readline(g_shell->name);
	if (!str)
		signal_d();
	if (ft_strlen(str) == 0)
	{
		free(str);
		return (NULL);
	}
	if (str && *str)
		add_history(str);
	return (str);
}

void	appointment(char **env)
{
	printf("------MINIHELL------\n");
	g_shell = malloc(sizeof(t_g_shell));
	g_shell->name = "\033[1;93m@yasinshell> \033[0m";
	g_shell->environ = env;
	ft_fill();
	signal(SIGINT, handle_siginit);
	signal(SIGQUIT, SIG_IGN);
	g_shell->len = 0;
	g_shell->ctrl = 1;
	g_shell->fpid = 1;
	g_shell->exit_status = 0;
}

int	main(int argc, char **argv, char **env)
{
	char	*a;

	(void)argc;
	(void)*argv;
	a = malloc(1);
	a[0] = 0;
	appointment(env);
	while (1)
	{
		a = rl_gets(a);
		if (a && *a)
			g_shell->line = a;
		else
		{
			free(a);
			continue ;
		}
		if (!lexer())
			continue ;
		expander();
		if (!check_token())
			executor();
		free_list();
	}
	return (1);
}
