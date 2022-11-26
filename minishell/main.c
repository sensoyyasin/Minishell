/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:37:01 by ysensoy           #+#    #+#             */
/*   Updated: 2022/11/26 17:04:48 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)*argv;
	char *ptr = NULL;

	shell = malloc(sizeof(t_shell));
	environ = env;
	shell->sayi = 42;
	printf("------MINIHELL------\n");
	while (1)
	{
		signal(SIGINT, handle_siginit);
		 signal(SIGQUIT, SIG_IGN);
		ptr = readline("\033[0;92m@yasinshell> \033[0m");
		 //ptr = readline(">");
		 add_history(ptr);
		 if (!ptr)
		 {
			 printf("exit\n");
			 exit(EXIT_SUCCESS);
		}
		if (ptr[0] == 0)
			continue;
		shell->str = ft_split(ptr, ' ');
		shell->str_pipe = ft_split(ptr, '|');
		quote_sayici(shell);
		if (quote_sayici > 0)
			expand_quote(shell);
		pipe_sayici(shell);
		if (shell->pipe > 0)
		{
			shell_pipe_dup2(shell);
			sleep(1);
			continue;
		}
		else if (check(shell))
			continue;
		free(ptr);
	}
	return(0);
}
