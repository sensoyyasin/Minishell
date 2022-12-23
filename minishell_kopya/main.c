/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:43:06 by mtemel            #+#    #+#             */
/*   Updated: 2022/12/23 20:23:58 by mtemel           ###   ########.fr       */
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

/* int	normal(void)
{
	printf("g_shell2.:>%s<\n",g_shell->line);
	if(g_shell->line && *g_shell->line)
	{
		//printf("sh:>%s<\n",g_shell->line); -> NULL geliyor.
		free(g_shell->line);
		g_shell->line = NULL;
	}
	g_shell->line = readline(g_shell->name);
	if (!g_shell->line)
		signal_d();
	else if (g_shell->line && *(g_shell->line))
		add_history(g_shell->line);
	else if (g_shell->line[0] == 0)
		return (0);
	return (1);
} */

char	*rl_gets(char *str)
{
	if (str)
	{
		free(str);
	}
	str = readline(g_shell->name);
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
	g_shell->name = "\033[0;93m@yasing_shell> \033[0m";
	g_shell->environ = env;
	ft_fill();
	signal(SIGINT, handle_siginit);
	signal(SIGQUIT, SIG_IGN);
	g_shell->len = 0;
	g_shell->ctrl = 1;
	g_shell->fpid = 1;
}

int	main(int argc, char **argv, char **env)
{
	char	*a;

	(void)argc;
	(void)*argv;
	a = NULL;
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
