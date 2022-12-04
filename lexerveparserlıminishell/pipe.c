#include "minishell.h"

void	ft_pipe_counter()
{
	t_list *iter;

	iter = shell->arg;
	shell->pipe = 0;
	while (iter != NULL)
	{
		if (ft_strcmp(iter->content, "|"))
			shell->pipe++;
		iter = iter->next;
	}
}

void	run_cmd_with_pipe()
{
	ft_pipe_counter();
	ft_pipe_func();
}
