/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:45:50 by ysensoy           #+#    #+#             */
/*   Updated: 2022/10/23 15:14:03 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)*argv;
	(void)*env;
	t_list *shell;
	char *ptr = NULL;

	shell = malloc(sizeof(t_list*));
	printf("------MINIHELL------\n");
	while (1)
	{
		signal(SIGINT, handle_siginit);
		signal(SIGQUIT, SIG_IGN);
		ptr =  readline(ft_strjoin(getenv("USER"),"\033[0;92m@yasinshell >\033[0m"));
		add_history(ptr);
		if (!ptr)
		{
			printf("exit\n");
			exit(EXIT_SUCCESS);
		}
		if (ptr[0] == 0)
			continue;
		shell->str = ft_split(ptr, ' ');
		if (check(shell))
			continue;
		else
			printf("zsh: command not found\n");
	}
	return(0);
}

void handle_siginit(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	//// when user presses ctrl-c
}

//ft_readline
//lexer
//parser
//execute


//pipe -> redirection
