/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:43:06 by mtemel            #+#    #+#             */
/*   Updated: 2022/12/18 17:57:15 by mtemel           ###   ########.fr       */
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
	free(shell->line);
	exit(1);
}

int	normal(void)
{
	shell->line = readline(shell->name);
	if (!shell->line)
		signal_d();
	add_history(shell->line);
	if (shell->line[0] == 0)
		return (0);
	return (1);
}

void	appointment(char **env)
{
	printf("------MINIHELL------\n");
	shell = malloc(sizeof(t_shell));
	shell->name = "\033[0;93m@yasinshell> \033[0m";
	shell->environ = env;
	ft_fill();
	if (!shell->asd)
		write(2, "Env error!\n", 11);
	signal(SIGINT, handle_siginit);
	signal(SIGQUIT, SIG_IGN);
	shell->len = 0;
	shell->ctrl = 1;
	shell->fpid = 1;
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
			free(shell->line);
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
