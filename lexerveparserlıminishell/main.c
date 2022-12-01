#include "minishell.h"

void sighandler(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		//rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	signal_d()
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
		return(0);
	return(1);
}

void	appointment(char **env)
{
	printf("------MINIHELL------\n");
	shell = malloc(sizeof(t_shell));

	shell->name = "\033[0;92m@yasinshell> \033[0m";
	shell->environ = env;
	signal(SIGINT, sighandler);
	signal(SIGQUIT, SIG_IGN);

	shell->len = 0;
}

int	cmnd_length(void)
{
	int i;

	i = 0;
	while (shell->line[i] > 32 && shell->line[i] != '|' && shell->line[i] != '>' && shell->line[i] != '<' && shell->line[i])
		i++;
	return(i);
}

void	lexir(int count)
{
	int i = 0;
	char *temp;

	temp = malloc(sizeof(t_list));
	while (count-- > 0)
	{
		temp[i] = *(shell->line);
		shell->line++;
		i++;
	}
	temp[i] = '\0';
	ft_lstadd_back(&shell->arg, ft_lstnew(temp));
}

void	space_skip(void)
{
	int i;

	i = 0;
	while (shell->line[i] <= 32)
		shell->line++;
}

void	lexer(void)
{
	int count;
	t_list *temp;

	while (*shell->line)
	{
		space_skip();
		if (shell->arg == NULL || ft_strcmp("|", ft_lstlast(shell->arg)->content))
		{
			count = cmnd_length();
			lexir(count);
			continue;
		}
		count = token_compr();
		if (count > 0)
			lexir(count);
		count = text_cmpr();
		if (count > 0)
			lexir(count);
		temp = shell->arg;
	}
	return;
}

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)*argv;
	appointment(env);
	t_list *deneme;

	while (1)
	{
		if (!normal())
		{
			free(shell->line);
			continue;
		}
		lexer();
		//listeyi yazdirmak icin.
		deneme = shell->arg;
		while (deneme != NULL)
		{
			printf("Args : %s\n", deneme->content);
			free(deneme->content);
			deneme = deneme->next;
		}
		shell->arg = NULL;
	}
	return(1);
}
