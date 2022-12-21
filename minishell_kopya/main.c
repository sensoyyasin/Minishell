/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:43:06 by mtemel            #+#    #+#             */
/*   Updated: 2022/12/21 14:05:14 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_siginit(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		//rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	signal_d(void)
{
	printf("exit\n");
	free(g_shell->line);
	exit(1);
}

int	normal(void)
{
	g_shell->line = readline(g_shell->name);
	if (!g_shell->line)
		signal_d();
	add_history(g_shell->line);
	if (g_shell->line[0] == 0)
		return (0);
	return (1);
}

void	appointment(char **env)
{
	printf("------MINIHELL------\n");
	g_shell = malloc(sizeof(t_g_shell));
	g_shell->name = "\033[0;93m@yasing_shell> \033[0m";
	g_shell->environ = env;
	ft_fill();
	if (!g_shell->asd)
		write(2, "Env error!\n", 11);
	signal(SIGINT, handle_siginit);
	signal(SIGQUIT, SIG_IGN);
	g_shell->len = 0;
	g_shell->ctrl = 1;
	g_shell->fpid = 1;
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)*argv;
	appointment(env);
	while (1)
	{
		if (!normal())
		{
			free(g_shell->line);
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
