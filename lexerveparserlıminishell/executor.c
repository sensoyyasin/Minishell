#include "minishell.h"

int		pipe_stat()
{
	t_list	*iter;

	iter = shell->arg;
	while (iter != NULL)
	{
		if (ft_strcmp(iter->content, "|"))
		{
			if (iter->next == NULL)
			{
				printf("Sadece pipe var.\n");
				return(-1);
			}
		return(1);
		}
		iter = iter->next;
	}
	return(0);
}

void	executor()
{
	int	stat;

	stat = pipe_stat();
	if (stat)
		run_cmd_with_pipe();
	else if (!stat)
		run_cmd_without_pipe(shell->arg);
	else
		return ;
}
