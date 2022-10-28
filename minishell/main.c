/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:45:50 by ysensoy           #+#    #+#             */
/*   Updated: 2022/10/28 17:53:01 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)*argv;
	t_shell *shell;
	char *ptr = NULL;

	shell = malloc(sizeof(t_list*));
	shell->temp_env = env;
	printf("------MINIHELL------\n");
	while (1)
	{
		signal(SIGINT, handle_siginit);
		signal(SIGQUIT, SIG_IGN);
		ptr =  readline(ft_strjoin(getenv("USER"),"\033[0;92m@yasinshell> \033[0m"));
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
		pipe_sayici(shell);
		if (shell->pipe > 0)
		{
			shell_pipe_dup2(shell);
			continue;
		}
		else if (check(shell))
				continue;
		free(ptr);
	}
	return(0);
}
